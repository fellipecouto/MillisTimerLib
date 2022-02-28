/*-----------------------------------------------------------------------------------
  Program  : MillisTimerLib
  Descr    : Library to use the Millis function as a task scheduler.
             (Be careful with using the Delay function in other parts of the program)
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MillisTimerLib
  Date     : 2020-06-07
  -----------------------------------------------------------------------------------*/
#ifndef MillisTimerLib_h
#define MillisTimerLib_h
#include "Arduino.h"

class MillisTimerLib {
  public:
    //Initializes the library by passing the delay timer value in milliseconds
    MillisTimerLib(long delayTime);

    //Returns true every time cycle
    bool timer();
	
    //Sets a new delay timer value in milliseconds
    void setDelay(long delayTime);
	
    //Returns the current delay value in milliseconds
    long getDelay();
    
  private:
    unsigned long _oldTime = 0;
    long _time = 0;
};
#endif
