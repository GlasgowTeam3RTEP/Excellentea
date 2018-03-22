#ifndef SENSOR_H
#define SENSOR_H

/**A general class for simple HIGH/LOW sensors.
 */

class sensor
{
public:
    /** Class constructor 
    @param GPIO Raspberry pi pin connected to the sensor.
     */
    sensor(short GPIO);

    /** Initialisation procedure with wiringPi library */
    virtual void initialise();

    /**Reads boolean status of the sensor*/
    bool readStatus();
protected:
    short pin; //< Raspberry GPIO connected to sensor (wiringPi convention)
};

#endif