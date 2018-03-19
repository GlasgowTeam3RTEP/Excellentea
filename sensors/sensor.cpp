#include <wiringPi.h>
#include "sensor.h"

/** Class constructor */
sensor::sensor(short GPIO)
{
	pin = GPIO;
}

/** Initialisation procedure with wiringPi library */
void sensor::initialise()
{
	wiringPiSetup();
	pinMode(pin, INPUT);
}

/**Reads boolean status of the sensor*/
bool sensor::readStatus()
{
	return digitalRead(pin);
}