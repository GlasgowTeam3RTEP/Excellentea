#ifndef TEA_H
#define TEA_H

class tea{
 public:
  void setBrewTemperature(double temp);
  void setBrewTime(double time);
  double getBrewTemperature();
  double getBrewTime();
  tea(double brew_temp, double brew_time);
 private:
  double brew_temp;
  double brew_time;
};

#endif