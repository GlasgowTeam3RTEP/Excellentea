#include "Stepper.h"
#include <wiringPi.h>

Stepper::Stepper(short A1, short A2, short B1, short B2, int steps)
{
	coil_A_pin_1 = A1;
	coil_A_pin_2 = A2;
	coil_B_pin_1 = B1;
	coil_B_pin_2 = B2;
	motor_steps = steps;
}

void Stepper::initialise()
{
	wiringPiSetup();

	pinMode(coil_A_pin_1, OUTPUT);
	pinMode(coil_A_pin_2, OUTPUT);
	pinMode(coil_B_pin_1, OUTPUT);
	pinMode(coil_B_pin_2, OUTPUT);
}

void Stepper::setStep(bool w1, bool w2, bool w3, bool w4)
{
	digitalWrite(coil_A_pin_1, w1);
	digitalWrite(coil_A_pin_2, w2);
	digitalWrite(coil_B_pin_1, w3);
	digitalWrite(coil_B_pin_2, w4);
}

void Stepper::forwardRun(int interval, int revolutions)
{
	for (int i = 0; i < motor_steps*revolutions; i++)
	{
		setStep(1, 0, 1, 0);
		delay(interval);
		setStep(0, 1, 1, 0);
		delay(interval);
		setStep(0, 1, 0, 1);
		delay(interval);
		setStep(1, 0, 0, 1);
		delay(interval);
	}
}

void Stepper::backwardRun(int interval, int revolutions)
{
	for (int i = 0; i < motor_steps*revolutions; i++)
	{
		setStep(1, 0, 0, 1);
		delay(interval);
		setStep(0, 1, 0, 1);
		delay(interval);
		setStep(0, 1, 1, 0);
		delay(interval);
		setStep(1, 0, 1, 0);
		delay(interval);
	}
}

void Stepper::spin(int speed, int revolutions, bool direction)
{
	int interval = 1000.0/speed;
	if (direction)
	{
		forwardRun(interval, revolutions);
	} else
	{
		backwardRun(interval, revolutions);
	}
}