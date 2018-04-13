#include "Stepper.h"
#include <iostream>

int main() {
	int revs = 0;
	int speed = 0;
	bool direction;
	Stepper s1(24, 23, 22, 21, 64);
	s1.initialise();

	while (1) {
		std::cout << "Insert number of revolutions: ";
		std::cin>>revs;
		std::cout << "Insert speed: ";
		std::cin>>speed;
		std::cout << "Insert direction: ";
		std::cin>>direction;

		s1.spin(speed, revs, direction);
	}
}