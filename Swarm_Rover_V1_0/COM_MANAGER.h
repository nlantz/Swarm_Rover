#ifndef COM_MANAGER_H
#define COM_MANAGER_H

#include "Arduino.h"

class COM_MANAGER{ 
public:
  COM_MANAGER(); //Constructor 
  ~COM_MANAGER();        //Destructor
  void transmit(unsigned long data, int nbits);
  boolean transmitObjectDetect(unsigned long data, int nbits, int RxPin);
  void markObjectDetect(int uSec, int RxPin);
  void mark(int usec);
  void space(int usec);

};

#endif
