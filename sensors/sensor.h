#ifndef SENSOR_H
#define SENSOR_H

class sensor
{
public:
    sensor(short GPIO);
    virtual void initialize();
    virtual bool readStatus();
protected:
    short pin;
};

#endif