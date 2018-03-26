#include "Actuator.h"
#include "LocalThread.h"
#include "DS18B20.h"
#include "LiquidCrystal_I2C.h"
#include "Sensor.h"
#include "Stepper.h"
#include "Tea.h"

#include <chrono>
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

	lcd.on();
	std::ostringstream strs;

	//Check presence of water***
	while (1) {
		lcd.home();
		if (water_sensor.readStatus()) {
			lcd.print("Not ready");
		} else {
			lcd.print("Ready    ");
		}
		lcd.setCursor(0, 1);
		strs<<"T= "<<std::setprecision(5)<<temp_sensor.readTemp()<<" C";
		lcd.print(strs.str().c_str());
		strs.str(std::string());
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
//Check input from web GUI***
//Tea myTea(temp, time);

//Make tea***



//Define finished procedure***




