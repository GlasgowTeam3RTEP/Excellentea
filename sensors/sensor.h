#ifndef SENSOR_H
#define SENSOR_H

/**A general class for simple sensors.
 
*/

class sensor
{
public:
    sensor(short GPIO);		//<Class constructor
    virtual void initialise();	//<Initialisation of the sensor
    bool readStatus();		//<Read HIGH/LOW status 
protected:
    short pin; //< Raspberry GPIO connected to sensor (wiringPi convention)
};

#endif