#include "Tea.h"

Tea::Tea(double temp, double time){
	Tea::brew_temp = temp;
	Tea::brew_time = time;
}

void Tea::setBrewTemperature(double temp){
  Tea::brew_temp = temp;
}

void Tea::setBrewTime(double time){ 
  Tea::brew_time= time;
}

double Tea::getBrewTemperature(){
  return Tea::brew_temp;
}

double Tea::getBrewTime(){
  return Tea::brew_time;
}
