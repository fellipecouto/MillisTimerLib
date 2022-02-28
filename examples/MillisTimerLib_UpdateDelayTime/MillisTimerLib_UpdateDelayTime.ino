/*-----------------------------------------------------------------------------------
  Program  : MillisTimerLib - Update delay time
  Descr    : Library to use the Millis function as a task scheduler.
             (Be careful with using the Delay function in other parts of the program)
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MillisTimerLib
  Date     : 2020-06-07
  -----------------------------------------------------------------------------------*/
//Update delay time

#include <MillisTimerLib.h> //https://github.com/fellipecouto/MillisTimerLib [ http://www.efeitonerd.com.br ]

#define LED_1 13
#define BUTTON 4

//Initializes the library by passing the delay timer value in milliseconds
MillisTimerLib timer1(1000);

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  //LED 1 remains flashing at the set time and when the button is pressed the delay time is updated

  if (timer1.timer()) {
    digitalWrite(LED_1, !digitalRead(LED_1));
  }

  if (digitalRead(BUTTON) == LOW) {
    timer1.setDelay(200);
  }

}
