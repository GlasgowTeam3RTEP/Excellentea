#include "sensor.h"

#ifndef DS18B20_H
#define DS18B20_H
#include <string>

class ds18b20 : sensor
{
public:
    ds18b20(short GPIO, std::string dev_id);
    void initialize();
    void setId(std::string dev_id);
    double readTemp();
private:
    std::string device_id;
};

#endif