#include "tea.h"

tea::tea(double temp, double time){
	tea::brew_temp = temp;
	tea::brew_time = time;
}

void tea::setBrewTemperature(double temp){
  tea::brew_temp = temp;
}

void tea::setBrewTime(double time){ 
  tea::brew_time= time;
}

double tea::getBrewTemperature(){
  return tea::brew_temp;
}

double tea::getBrewTime(){
  return tea::brew_time;
}
