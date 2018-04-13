#include "Classes/Actuator.h"
#include "Classes/DS18B20.h"
#include "Classes/LiquidCrystal_I2C.h"
#include "Classes/Sensor.h"
#include "Classes/Stepper.h"
#include "Classes/Tea.h"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <string>
#include <thread>

std::string readTag(std::string tag, std::string filename) {
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

void writeTag(std::string tag, std::string value, std::string filename) {
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

int main() {

	//Define components***
	Sensor water_sensor(0); //PIN 12
	DS18B20 temp_sensor(7, "28-0516a06e58ff"); //PIN 7 and bus id
	Stepper strainer(24, 23, 22, 21, 64); //coils terminals and steps
	Actuator heat_elem(30);

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
	heat_elem.switchOff();
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
		lcd.clear();
		
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
		std::cout<<"Heating up to "<< myTea.getBrewTemperature()<<"degrees."<<std::endl;
		while (temp_sensor.readTemp() < myTea.getBrewTemperature()) {
			lcd.setCursor(0, 1);
			strs << "T= " << std::setprecision(5) << temp_sensor.readTemp() << " C     ";
			lcd.print(strs.str().c_str());
			std::cout<<strs.str().c_str()<<std::endl;
			strs.str(std::string());
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		//Turn off heating element***
		heat_elem.switchOff();
		std::cout<<"Heating element OFF"<<std::endl;
		
		//Lower strainer***
		lcd.clear();
		lcd.print("Lowering");
		lcd.setCursor(0,1);
		lcd.print("strainer");
		std::cout<<"Strainer DOWN"<<std::endl;
		strainer.spin(350, 30, 0);
		
		//Sleep for brewing time***
		lcd.clear();
		lcd.print("Brewing...");
		std::cout<<"Brewing"<<std::endl;
		int duration = myTea.getBrewTime() * 60 ;
		
		
		clock_t begin = clock();
		double time_elapsed = 0;
		double time_left = 0;
		int minutes_left = 0;
		int seconds_left = 0;
		
		while ((double(clock()-begin)/ CLOCKS_PER_SEC*1000)<duration) {
			time_elapsed = double(clock()-begin)/ CLOCKS_PER_SEC*1000;
			time_left = duration - time_elapsed;
			minutes_left = time_left/60;
			seconds_left = (time_left/60 - (double(minutes_left)))*60;
			
			strs <<minutes_left<<":"<<seconds_left<<"      ";
			lcd.setCursor(0,1);
			lcd.print(strs.str().c_str());
			std::cout<<strs.str().c_str()<< "left"<<std::endl;
			strs.str(std::string());
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
  
		//Pull-up strainer***
		lcd.clear();
		lcd.print("Pulling up");
		lcd.setCursor(0,1);
		lcd.print("strainer");
		std::cout<<"Strainer UP"<<std::endl;
		strainer.spin(350, 60,1);

		//Update on progress***
		lcd.clear();
		lcd.print("Your tea is");
		lcd.setCursor(0, 1);
		lcd.print("ready!!!");
		std::cout<<"FINISHED"<<std::endl;
		writeTag("DONE", "YES", configFile);
		std::this_thread::sleep_for(std::chrono::milliseconds(3 * 60 * 1000));
	}
}

