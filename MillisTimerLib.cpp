/*-----------------------------------------------------------------------------------
  Program  : MillisTimerLib
  Descr    : Library to use the Millis function as a task scheduler.
             (Be careful with using the Delay function in other parts of the program)
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MillisTimerLib
  Date     : 2020-06-07
  -----------------------------------------------------------------------------------*/
#include "MillisTimerLib.h"
#include <Arduino.h>

unsigned long _oldTime = 0;
unsigned long _time = 0;

MillisTimerLib::MillisTimerLib(long delayTime) {
  setDelay(delayTime);
}

bool MillisTimerLib::timer() {
  if (timerCount() >= _time) {
      reset();
      return true;
    }
  return false;
}

long MillisTimerLib::timerCount() {
  return millis() - _oldTime;
}

void MillisTimerLib::setDelay(long delayTime) {
  if (delayTime > 0) {
    _time = delayTime;
  } else {
    _time = 0;
  }
}

long MillisTimerLib::getDelay() {
  return _time;
}

void MillisTimerLib::reset() {
  _oldTime = millis();
}