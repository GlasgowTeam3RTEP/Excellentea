#include "Stepper.h"
#include <iostream>

int main()
{
	int revs = 0;
	int speed = 0;
	bool direction;
	Stepper s1(25, 24, 22, 23, 64);
	s1.initialise();
	
	std::cout<<"Insert number of revolutions: ";
	std::cin>>revs;
	std::cout<<"Insert speed: ";
	std::cin>>speed;
	std::cout<<"Insert direction: ";
	std::cin>>direction;
	
	s1.spin(speed, revs, direction);
}