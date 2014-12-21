#include "COM_MANAGER.h" //include the declaration for this class

#define TOPBIT 0x80000000 //mask for transmit 

// Pulse parms are *50-100 for the Mark and *50+100 for the space
// First MARK is the one after the long gap
// pulse parameters in usec
#define NEC_HDR_MARK	9000
#define NEC_HDR_SPACE	4500
#define NEC_BIT_MARK	560
#define NEC_ONE_SPACE	1600
#define NEC_ZERO_SPACE	560

#define MARK  1 //defines mark for IR transmit
#define SPACE 0 //defiins space for IR transmit


byte Transmit_pin = A4; //default to A4 as per the schematic
unsigned long start_time; //Variable for transmit calc. 

COM_MANAGER::COM_MANAGER(byte pin){
  Transmit_pin = pin;
}

COM_MANAGER::~COM_MANAGER(){
  /*nothing to destruct*/
}

//function for transmitting a bit string. 
void COM_MANAGER::transmit(unsigned long data, int nbits){

  //Send the initial mark+space fotr handshake 
  mark(NEC_HDR_MARK);              
  space(NEC_HDR_SPACE);

  //send the data
  for (int i = 0; i < nbits; i++) { //cycle through all the bits 
    if (data & TOPBIT) {            //if the topbit is 1 send a 1
      mark(NEC_BIT_MARK);
      space(NEC_ONE_SPACE);
    } 
    else {                          //if the topbit is 0 send a 0
      mark(NEC_BIT_MARK);
      space(NEC_ZERO_SPACE);
    }  
    data <<=1;                      //bitshift the data
  }

  //TODO Send ranging signal 

  //send the ending mark+space 
  mark(NEC_BIT_MARK);
  space(0);
}

void COM_MANAGER::mark(int time) {
  // Sends an IR mark for the specified number of microseconds.
  // The mark output is modulated at the PWM frequency.
}

/* Leave pin off for time (given in microseconds) */
void COM_MANAGER::space(int time) {
  // Sends an IR space for the specified number of microseconds.
  // A space is no output, so the PWM output is disabled.
}


