/*-----------------------------------------------------------------------------------
  Program  : MillisTimerLib - Blink Leds with button
  Descr    : Library to use the Millis function as a task scheduler.
             (Be careful with using the Delay function in other parts of the program)
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MillisTimerLib
  Date     : 2020-06-07
  -----------------------------------------------------------------------------------*/
//Blink Leds with button

#include <MillisTimerLib.h> //https://github.com/fellipecouto/MillisTimerLib [ http://www.efeitonerd.com.br ]

#define LED_1  2
#define LED_2  3
#define BUTTON 4

//Initializes the library by passing the delay timer value in milliseconds
MillisTimerLib timer1(500);

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  //While LED 1 remains blinking, LED 2 lights up when the button is pressed
  
  if (timer1.timer()) {
    digitalWrite(LED_1, !digitalRead(LED_1));
  }

  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED_2, HIGH);
  } else {
    digitalWrite(LED_2, LOW);
  }

}
