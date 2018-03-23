/**Class for the digital temperature sensor DS18B20. */

#include "sensor.h"
#include <string>

#ifndef DS18B20_H
#define DS18B20_H

class DS18B20 : Sensor
{
public:

    /** Class constructor.
     *	Build a temperature sensor object with the pin number and the unique device ID.
 @param GPIO pin number (wiringPi convention)
 @param dev_id device ID on the bus as a string 
     */
    DS18B20(short GPIO, std::string dev_id);

    /** Initialisation procedure.
	Activates the one-wire interface from the Raspberry PI.
     */
    void initialise();
    
    /** Read the temperature from the sensor.
     Request the temperature value from the sensor and returns a double precision value.
     */
    double readTemp();
private:
    std::string device_id; //<String that uniquely identifies each sensor on the bus
};

#endif