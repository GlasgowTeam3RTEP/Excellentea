/** A class defining a type of tea by its brewing time and temperature.
 *  Define a tea object in the context of Excellentea in terms of its brewing time 
 *  and temperature.
 *
 *  @version Excellentea 1.0
 *  
 *  @author Simone Marcigaglia
 */
#ifndef TEA_H
#define TEA_H

class Tea
{
public:
    /** Class constructor.
     Create a tea object.
     @param brew_temp Brewing temperature in °C.
     @param brew_time Brewing time in minutes.
     */
    Tea(double brew_temp, double brew_time);

    /** Set the brewing temperature.
     @param temp Brewing temperature in °C.
     */
    void setBrewTemperature(double temp);

    /** Set the brewing time.
     @param time Brewing time in minutes.
     */
    void setBrewTime(double time);

    /** Read the brewing temperature.
     */
    double getBrewTemperature();

    /** Read the brewing time.
     */
    double getBrewTime();

private:
    double brew_temp;
    double brew_time;
};

#endif