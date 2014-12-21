#include "COM_MANAGER.h" //include the declaration for this class

byte Transmit_pin = A4; //default to A4 as per the schematic

COM_MANAGER::COM_MANAGER(byte pin){
  Transmit_pin = pin;
}

COM_MANAGER::~COM_MANAGER(){
  /*nothing to destruct*/
}

//function for transmitting a bit string. 
void COM_MANAGER::transmit(unsigned long data){
  
}
