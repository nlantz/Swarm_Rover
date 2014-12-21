//This is an example of how to build a header file

#ifndef LED13_H
#define LED13_H

#include "Arduino.h"

class LED13 { 
public:
  LED13(); //Constructor 
  ~LED13(); //Destructor
  void on();
  void off();
  void blink(int time);
};

#endif

