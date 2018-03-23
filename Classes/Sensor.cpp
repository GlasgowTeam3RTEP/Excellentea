#include <wiringPi.h>
#include "Sensor.h"

Sensor::Sensor(short GPIO)
{
	pin = GPIO;
}

void Sensor::initialise()
{
	wiringPiSetup();
	pinMode(pin, INPUT);
}

bool Sensor::readStatus()
{
	return digitalRead(pin);
}