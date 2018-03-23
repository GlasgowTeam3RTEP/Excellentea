/** A class to control stepper motors.
 This class controls general stepper motors (connected via transistor arrays) by
 defining each step as HIGH or LOW values of the coils and cycling through them 
 after a defined interval.
 */

#ifndef STEPPER_H
#define STEPPER_H

class Stepper
{
public:
    /** Class constructor.
     @param A1 First pin of the first coil
     @param A2 Second pin of the first coil
     @param B1 First pin of the second coil
     @param B2 Second pin of the second coil
     @param steps Number of the steps of the stepper motor
     */
    Stepper(short A1, short A2, short B1, short B2, int steps);

    /** Initialisation procedure.
     Function required to initialise the stepper motor to wiringPi standards.     
     */
    void initialise();

    /** Spin the stepper motor.
     Spin the stepper motor in a certain direction and at a certain speed 
     as defined by the input parameters.
     @param speed spinning speed
     @param revolutions number of revolutions
     @direction clockwise or anti-clockwise direction specified 
     as a boolean value.
     */
    void spin(int speed, int revolutions, bool direction);

private:
    short coil_A_pin_1; //< pin 1 of first coil
    short coil_A_pin_2; //< pin 2 of first coil
    short coil_B_pin_1; //< pin 1 of second coil
    short coil_B_pin_2; //< pin 2 of second coil
    int motor_steps; //< number of steps of the stepper motor

    /** Define a specific step of the stepper motor.
     Input parameters are high/low values of each terminal.
     */
    void setStep(bool a1, bool a2, bool b1, bool b2);

    /** Spin the stepper in the forward direction
     @param interval Interval between subsequent steps
     @param steps Number of steps
     */
    void forwardRun(int interval, int steps);
    
    /** Spin the stepper in the backward direction
     @param interval Interval between subsequent steps
     @param steps Number of steps
     */
    void backwardRun(int interval, int steps);
};

#endif