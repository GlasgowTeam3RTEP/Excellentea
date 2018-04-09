#include "Actuator.h"
#include "LocalThread.h"
#include "DS18B20.h"
#include "LiquidCrystal_I2C.h"
#include "Sensor.h"
#include "Stepper.h"
#include "Tea.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <string>
#include <thread>

LocalThread::LocalThread() { }

void LocalThread::run() {

	//Define components***
	Sensor water_sensor(29); //PIN 12
	DS18B20 temp_sensor(7, "28-0516a06e58ff"); //PIN 7 and bus id
	Stepper strainer(22, 23, 24, 25, 64); //coils terminals and steps
	Actuator heat_elem(5);

	//Define Display connection***
	// i2c address
	uint8_t i2c = 0x27;
	// Control line PINs
	uint8_t en = 2;
	uint8_t rw = 1;
	uint8_t rs = 0;

	// Data line PINs
	uint8_t d4 = 4;
	uint8_t d5 = 5;
	uint8_t d6 = 6;
	uint8_t d7 = 7;

	// Backlight PIN
	uint8_t bl = 3;

	// LCD display size
	uint8_t rows = 2;
	uint8_t cols = 16;
	LiquidCrystal_I2C lcd("/dev/i2c-1", i2c, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

	//Initialise components***
	water_sensor.initialise();
	temp_sensor.initialise();
	strainer.initialise();
	heat_elem.initialise();
	lcd.begin(cols, rows);
	std::cout << "Initialisation complete!!" << std::endl;

	//Configurations file
	std::string configFile = "/var/www/html/config";

	//Turn on LCD
	lcd.on();
	std::ostringstream strs;
	while (1) {
		//Initialise config file
		writeTag("READY", "NO", configFile);
		writeTag("MAKE", "NO", configFile);
		writeTag("PROGR", "NO", configFile);
		writeTag("DONE", "NO", configFile);

		//Check presence of water***
		while (1) {
			lcd.home();
			if (water_sensor.readStatus()) {
				//Print status on lcd
				lcd.print("Not ready      ");
				//change flag in configuration file
				if (readTag("READY", configFile) == "YES") {
					writeTag("READY", "NO", configFile);
				}
			} else {
				//Print status on lcd
				lcd.print("READY!         ");
				//change flag in configuration file
				if (readTag("READY", configFile) == "NO") {
					writeTag("READY", "YES", configFile);
				}
				if (readTag("MAKE", configFile) == "YES") {
					break;
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		//Read tea characteristics
		double desired_temp = std::stod(readTag("TEMP", configFile));
		double desired_time = std::stod(readTag("TIME", configFile));
		Tea myTea(desired_temp, desired_time);

		//Turn ON heating element***
		heat_elem.switchOn();
		lcd.clear();
		lcd.print("Activating...");

		//Update progress flag
		writeTag("PROGR", "YES", configFile);

		//Check water temperature***
		lcd.clear();
		lcd.print("Heating up...");
		while (temp_sensor.readTemp() < myTea.getBrewTemperature()) {
			lcd.setCursor(0, 1);
			strs << "T= " << std::setprecision(5) << temp_sensor.readTemp() << " C   ";
			lcd.print(strs.str().c_str());
			strs.str(std::string());
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		//Turn off heating element***
		heat_elem.switchOff();

		//Lower strainer***
		strainer.spin(200, 20, 0);
		lcd.clear();
		lcd.print("Brewing...");

		//Sleep for brewing time***
		int duration = myTea.getBrewTime() * 60 * 1000;
		std::this_thread::sleep_for(std::chrono::milliseconds(duration));

		//Pull-up strainer***
		strainer.spin(200, 20, 1);

		//Update on progress***
		lcd.clear();
		lcd.print("Your tea is");
		lcd.setCursor(0, 1);
		lcd.print("ready!!!");
		writeTag("DONE", "YES", configFile);
		std::this_thread::sleep_for(std::chrono::milliseconds(15 * 60 * 1000));
	}
}

std::string LocalThread::readTag(std::string tag, std::string filename) {
	std::ifstream readFile(filename.c_str());
	std::string line = "";
	std::string fileTag = "";
	std::string fileValue = "";
	int pos = 0;

	while (getline(readFile, line)) {
		pos = line.find("\t");
		if (pos != 0) {
			fileTag = line.substr(0, pos);
			fileValue = line.substr(pos + 1);
			if (tag == fileTag) {

				return fileValue;
			}
		}
	}
	return "not found";
}

void LocalThread::writeTag(std::string tag, std::string value, std::string filename) {
	std::string tempFile = "writeTag.tmp";
	std::ifstream readFile(filename.c_str());
	std::ofstream writeFile(tempFile.c_str());
	std::string line = "";
	std::string fileTag = "";
	std::string fileValue = "";
	int pos = 0;
	bool replaced = false;

	while (getline(readFile, line)) {
		pos = line.find("\t");
		if (pos != 0) {
			fileTag = line.substr(0, pos);
			fileValue = line.substr(pos + 1);
			if (tag == fileTag) {
				line = fileTag + '\t' + value;
				replaced = true;
			}
			writeFile << line << std::endl;
		}
	}
	writeFile.close();
	readFile.close();

	if (replaced) {
		rename(tempFile.c_str(), filename.c_str());
		//allow apache to read and modify contents
		system("sudo chown -R www-data: /var/www/html");
	} else {
		remove(tempFile.c_str());
	}
}

