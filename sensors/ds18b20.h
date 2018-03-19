/**Class for the digital temperature sensor DS18B20. */

#include "sensor.h"
#include <string>

#ifndef DS18B20_H
#define DS18B20_H


class ds18b20 : sensor
{
public:
    ds18b20(short GPIO, std::string dev_id);
    void initialise();
    void setId(std::string dev_id);
    double readTemp();
private:
    std::string device_id;  //<String that uniquely identifies each sensor on the bus
};

#endif