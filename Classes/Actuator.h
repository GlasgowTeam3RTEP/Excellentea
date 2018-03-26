/**A general class for external loads.
 This class merely allows the HIGH/LOW switching of pins ideal for external 
 loads connected through logic-level MOSFETs/transistor. 
 
 @version Excellentea 1.0
 
 @author Simone Marcigaglia
 */

#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator
{
public:
    /** Class constructor 
    @param GPIO Raspberry pi pin connected to the actuator.
     */
    Actuator(short GPIO);

    /** Initialisation procedure with the wiringPi library */
    void initialise();

    /**Sets the value of the pin to HIGH*/
    void switchOn();

    /**Sets the value of the pin to LOW*/
    void switchOff();

private:
    short pin; //< Raspberry GPIO connected to the actuator(wiringPi convention)
};

#endif