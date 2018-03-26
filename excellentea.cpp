#include "Classes/LocalThread.h"
#include "Classes/CppThread.h"
#include "Classes/WebThread.h"
#include <iostream>
#include <wiringPi.h>

int main() {
	//Define threads
	WebThread remoteGUI;
	LocalThread localControl;

	//Start threads
	remoteGUI.start();
	localControl.start();
	
	remoteGUI.join();
	localControl.join();

}
