# MillisTimer
Library to use the Millis function as a task scheduler

*(Be careful with using the Delay function in other parts of the program)*

## Usage

```c++
//Initializes the library by passing the delay timer value in milliseconds
MillisTimerLib(long delayTime);

//Returns true every time cycle
bool timer();

//Returns the delay count in milliseconds
long timerCount();

//Sets a new delay timer value in milliseconds
void setDelay(long delayTime);

//Returns the currently configured delay value in milliseconds
long getDelay();

//Reset timer counter
void reset();
```

Author : Fellipe Couto [ http://www.efeitonerd.com.br ]

Date : 2020-06-07
