#ifndef STEPPER_H
#define STEPPER_H

class stepper
{
public:
    void initialize();
    void spin(int speed, int revolutions, bool direction);
    stepper(short A1, short A2, short B1, short B2, int steps);
private:
    short coil_A_pin_1; //PINK
    short coil_A_pin_2; //ORANGE
    short coil_B_pin_1; //BLUE
    short coil_B_pin_2; //YELLOW
    int motor_steps;
    void setStep(bool a1, bool a2, bool b1, bool b2);
    void forwardRun(int interval, int steps);
    void backwardRun(int interval, int steps);
};

#endif