<img src="https://github.com/GlasgowTeam3RTEP/ExcellenTea/blob/master/images/Banner.png" alt="Excellentea" width="1000">
# Description

Excellentea is an automatic tea maker. The user can operate the machine remotely through an online interface. 
In other words, you can order your tea, by chosing from several modes, as you leave work and find it ready when you get home. 
It also comes with the option of  controlling the machine using control buttons and an LCD display.
<p align="center">
<a href="https://www.youtube.com/watch?v=Gr951TFXX7w
" target="_blank"><img src="http://img.youtube.com/vi/Gr951TFXX7w/0.jpg" 
alt="Promotional video" width="360" height="270" border="10" /></a>
</p>

# Usage

## User operation
[//]: # (instruct other people on how to use your project after they’ve installed it)

1. Load your cup with water

2. Load your tea infuser with the tea of your choice
---

For remote control: 

3. Activate the tea maker from the online user interface

4. Choose the brewing mode of your tea
---

For on-machine control: 

3. Activate using inbuilt interface

4. Navigate with control buttons and select your preferred program
---

5. Wait...tea is ready:)


# Hardware

## Key components

- 1 Raspberry PI microcontroller board (tested on version 3 Model B)
- 1 Stepper motor (MIKROE-1530)
- 1 Digital temperature sensor (ds18b20)
- 12V DC power supply 
- 1 heating element (12V) (B004O8BGXE)
- 1 tea infuser 
- 1 reed float sensor (59630)
- 2 18-pin through hole socket (ED18DT)
- 2 Bipolar transistor array (ULN2803A)
- LCD
- 2 N-channel logic-level MOSFET (FQP30N06L)
- MOSFET heat sink (507222B00000G)

## Additional components
The project also requires standard passive components (e.g. resistors), prototyping tools (e.g. breadboard/pcb) and materials for the encasing. See the [circuit schematics](Main.sch) for details. 

## Protocol

The digital temperature sensor DS18B20 communicates with the board through a 1-wire protocol wired on pin 7 (BCM4). The reed float sensor only outputs two-states so a communication protocol is not required. 

## Prerequisites

The raspberry PI must be connected to the internet for remote access.

# Software

## Flow diagram

![Flow Diagram](https://github.com/GlasgowTeam3RTEP/ExcellenTea/blob/master/images/Program_flow.png "Flow diagram of the tea maker")

# Authors

* [**Andrea Spanou**](https://github.com/andreaspanou) - *Initial work* 
* [**Ciaran McGeady**](https://github.com/CiaranAnthony) - *Initial work*
* [**Simone Marcigaglia**](https://github.com/SimoneMarcigaglia) - *Initial work*

See also the list of [contributors](https://github.com/GlasgowTeam3RTEP/ExcellenTea/contributors) who participated in this project.

# Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

# License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

# Acknowledgments

We would like to thank the weather in Glasgow for making us think about tea all the time.
