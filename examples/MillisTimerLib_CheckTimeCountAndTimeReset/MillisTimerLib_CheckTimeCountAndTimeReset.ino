/*-----------------------------------------------------------------------------------
  Program  : MillisTimerLib - Update delay time based on current delay time
  Descr    : Library to use the Millis function as a task scheduler.
             (Be careful with using the Delay function in other parts of the program)
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MillisTimerLib
  Date     : 2020-06-07
  -----------------------------------------------------------------------------------*/
//Check time count and time reset
//Follow the delay time update by the serial monitor

#include <MillisTimerLib.h>  //https://github.com/fellipecouto/MillisTimerLib [ http://www.efeitonerd.com.br ]

#define LED_1 13
#define BUTTON 4

//Initializes the library by passing the delay timer value in milliseconds
MillisTimerLib timer1(5000);

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.print("Current delay value: ");
  Serial.println(timer1.getDelay());
}

void loop() {
  //LED 1 is blinking for the set time and whenever the button is pressed the timer will be reset

  Serial.print("Counter value: ");
  Serial.println(timer1.timerCount());
  delay(100);

  if (timer1.timer()) {
    Serial.println("\t\t--> TIME!");
    digitalWrite(LED_1, !digitalRead(LED_1));
  }

  if (digitalRead(BUTTON) == LOW) {
    Serial.println("\t\t-->Button pressed! The timer will be reset!");
    delay(1000);
    timer1.reset();
  }
}