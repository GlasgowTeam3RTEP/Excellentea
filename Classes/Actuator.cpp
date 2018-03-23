#include <wiringPi.h>
#include "Actuator.h"

Actuator::Actuator(short GPIO) {
	pin = GPIO;
}

void Actuator::initialise() {
	wiringPiSetup();
	pinMode(pin, OUTPUT);
}

void Actuator::switchOn() {
	digitalWrite(pin, HIGH);
}

void Actuator::switchOff() {
	digitalWrite(pin, LOW);
}