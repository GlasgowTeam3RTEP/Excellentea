<img src="https://github.com/GlasgowTeam3RTEP/ExcellenTea/blob/master/Images/Banner_Github.png" alt="Excellentea" width="1200">

# Description

Excellentea is an automatic tea maker. The user can operate the machine remotely through an online interface. 
In other words, you can order your tea, by chosing from several modes, as you leave work and find it ready when you get home. 
It also comes with the option of controlling the machine using control buttons and an LCD display.

# Installation

## Prerequisites
The application requires the user to have Apache and php installed on their Raspberry Pi. Use your favourite package manager to install the packages _apache2_ and _php_ or, alternatively, open the terminal and use the commands below.
```
sudo apt-get update
sudo apt-get install apache2 php libapache2-mod-php -y
```
The One-wire and I2C protocols must be activated for the application to work. Run the following command:
```
sudo raspi-config
```
and navigate to _Interfacing options_ to enable _I2C_ and _1-Wire_.

## Installation procedure
Clone the repository to your Raspberry Pi and run the following commands:
```
./configure
make
make install
```
Initialise and start the apache web interface (change the default pi with your user name):
```
sudo chown -R pi /var/www/html/
rm /var/www/html/index.html
cp GUI/* /var/www/html/
sudo reboot
```
Find your local IP with:
```
hostname -I
```
The program can then be started by running the command
```
sudo excellentea
```
from the terminal, and the web interface will be available at the IP address found previously. The web interface can then be accessed by external hosts by enabling router port forwarding.

# Usage
[//]: # (instruct other people on how to use your project after they’ve installed it)

1. Load your cup with water

2. Load your tea infuser with the tea of your choice

3. Activate the tea maker from the online user interface

4. Choose the brewing mode of your tea

5. Wait...tea is ready:)

# Configuration
An in-depth description of the project can be found on our [wiki](https://github.com/GlasgowTeam3RTEP/Excellentea/wiki). The following sections will briefly describe the main components and their implementation in the overall design. 

## Hardware

### Key components
- 1 Raspberry PI microcontroller board (tested on version 3 Model B)
- 1 Stepper motor (MIKROE-1530)
- 1 Digital temperature sensor (ds18b20)
- 12V DC power supply 
- 1 heating element (12V) (B004O8BGXE)
- 1 tea infuser 
- 1 reed float sensor (59630)
- 2 Darlington transistor array (ULN2803A)
- LCD
- 2 N-channel logic-level MOSFET (FQP30N06L)
- MOSFET heat sink (507222B00000G)

### Additional components
The project also requires standard passive components (e.g. resistors), prototyping tools (e.g. breadboard/pcb) and materials for the encasing. Check out our [wiki](https://github.com/GlasgowTeam3RTEP/Excellentea/wiki) for details. 

### Protocol
The digital temperature sensor DS18B20 communicates with the board through the one-wire protocol on pin 7 (BCM4). The reed float sensor only outputs two-states so a communication protocol is not required. 

## Software
The software was written to reflect the data flow depicted below. The float switch is used as a safety feature to ensure that the heating element cannot be switched on in the absence of water. Once the cup is full of water, the program will wait for a user interaction through the web interface (implemented as a second thread with a PHP script on an apache web server). The main thread will receive the signal to initiate the tea making procedure with two main parameters, the brewing temperature and the brewing time. The heating element is turned on and the temperature is monitored periodically via the sensor on the One-wire bus. Once the temperature reaches the desired value, the heating element is switched off and the preloaded tea infuser is lowered by the stepper motor. Once the desired brewing time has elapsed, the stepper motor rewinds the strainer and the tea is ready.  
![Data Flow](https://github.com/GlasgowTeam3RTEP/ExcellenTea/blob/master/Images/Dataflow.png "Flow diagram of the tea maker")

# Authors
* [**Andrea Spanou**](https://github.com/andreaspanou) - *Initial work* 
* [**Ciaran McGeady**](https://github.com/CiaranAnthony) - *Initial work*
* [**Simone Marcigaglia**](https://github.com/SimoneMarcigaglia) - *Initial work*

See also the list of [contributors](https://github.com/GlasgowTeam3RTEP/ExcellenTea/contributors) who participated in this project. Check out our [Twitter](https://twitter.com/Excellentea1) page to be up-to-date with the latest developments!

# Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

# License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

# Acknowledgments

We would like to thank the weather in Glasgow for making us think about tea all the time.
