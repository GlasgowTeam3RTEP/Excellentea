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
};

#endif