#include <wiringPi.h>
#include "sensor.h"

sensor::sensor(short GPIO)
{
	pin = GPIO;
}

void sensor::initialize()
{
	wiringPiSetup();
	pinMode(pin, INPUT);
}

bool sensor::readStatus()
{
	return digitalRead(pin);
}