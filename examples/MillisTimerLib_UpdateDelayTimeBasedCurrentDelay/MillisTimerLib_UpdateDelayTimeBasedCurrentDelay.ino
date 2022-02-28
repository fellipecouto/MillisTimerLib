/*-----------------------------------------------------------------------------------
  Program  : MillisTimerLib - Update delay time based on current delay time
  Descr    : Library to use the Millis function as a task scheduler.
             (Be careful with using the Delay function in other parts of the program)
  Author   : Fellipe Couto [ http://www.efeitonerd.com.br ]
  GitHub   : https://github.com/fellipecouto/MillisTimerLib
  Date     : 2020-06-07
  -----------------------------------------------------------------------------------*/
//Update delay time based on current delay time
//Follow the delay time update by the serial monitor

#include <MillisTimerLib.h> //https://github.com/fellipecouto/MillisTimerLib [ http://www.efeitonerd.com.br ]

#define LED_1 13
#define BUTTON 4

//Initializes the library by passing the delay timer value in milliseconds
MillisTimerLib timer1(1000);

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.print("Current delay value: ");
  Serial.println(timer1.getDelay());
}

void loop() {
  //LED 1 remains flashing at the set time and whenever the button is pressed the delay time is updated with a difference of 200 milliseconds

  if (timer1.timer()) {
    digitalWrite(LED_1, !digitalRead(LED_1));
  }

  bool isPressed = false;
  while (digitalRead(BUTTON) == LOW) {
    isPressed = true;
    delay(200);
  }

  if (isPressed) {
    long newDelay = timer1.getDelay() - 200;
    timer1.setDelay(newDelay);
    Serial.print("Button pressed! New delay value: ");
    Serial.println(timer1.getDelay());
  }
  
}
