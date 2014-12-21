#ifndef COM_MANAGER_H
#define COM_MANAGER_H

#include "Arduino.h"

class COM_MANAGER{ 
public:
  COM_MANAGER(byte pin); //Constructor 
  ~COM_MANAGER();        //Destructor
  void transmit(unsigned long data, int nbits);
  void mark(int usec);
  void space(int usec);

};

#endif
