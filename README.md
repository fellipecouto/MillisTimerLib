# MillisTimer
Library to use the Millis function as a task scheduler

*(Be careful with using the Delay function in other parts of the program)*

## Usage

```Arduino
//Initializes the library by passing the delay timer value in milliseconds
MillisTimerLib(long delayTime);

//Returns true every time cycle
bool timer();

//Sets a new delay timer value in milliseconds
void setDelay(long delayTime);

//Returns the current delay value in milliseconds
long getDelay();
```

Author : Fellipe Couto [ http://www.efeitonerd.com.br ]

Date : 2020-06-07
