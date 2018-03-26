/** A thread that handles the web interface.
 * 
 *  @version Excellentea 1.0
 *
 *  @author Simone Marcigaglia
 */

#ifndef WEBTHREAD_H
#define WEBTHREAD_H
#include "CppThread.h"

class WebThread : public CppThread
{
public:

    /** Class constructor
     */
    WebThread();

private:

    /** Main body of the thread.
     */
    void run();

private:
    // Your private data
};

#endif