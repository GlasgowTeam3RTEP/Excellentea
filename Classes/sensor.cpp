#include <wiringPi.h>
#include "sensor.h"

sensor::sensor(short GPIO)
{
	pin = GPIO;
}

void sensor::initialise()
{
	wiringPiSetup();
	pinMode(pin, INPUT);
}

bool sensor::readStatus()
{
	return digitalRead(pin);
}