/** Thread that controls machine operation.
 *  This thread employs that cppThread class found at https://github.com/berndporr/cppThread
 *  to control the local operations of the tea maker.
 *
 *  @version Excellentea 1.0
 *
 *  @author Simone Marcigaglia
 */
#ifndef LOCALTHREAD_H
#define LOCALTHREAD_H

#include "CppThread.h"
#include <string>

class LocalThread : public CppThread
{
public:

    /** Class constructor
     */
    LocalThread();

private:

    /** Main body of the thread.
     */
    void run();

    /** Read the value associated with a certain tag.
     *	Opens the configuration file specified in filename and reads the value
     *	of the tag specified.
     *	@param tag String identifier for the parameter.
     *	@param filename Configuration file to be read.
     */
    std::string readTag(std::string tag, std::string filename);

    /** Write the value associated with a certain tag.
     *	Opens the configuration file specified in filename and writes the specified 
     *	value on the corresponding tag.
     *	@param tag String identifier for the parameter.
     *	@param value Value to be written.
     *	@param filename Configuration file to be read.
     */
    void writeTag(std::string tag, std::string value, std::string filename);
};

#endif