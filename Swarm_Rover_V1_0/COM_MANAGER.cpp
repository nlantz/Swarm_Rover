#include "IRremote.h"
#include "IRremoteInt.h"

#include "COM_MANAGER.h" //include the declaration for this class
#include "COM_MANAGER_INT.h" //include external parameters file




int transmitPin = A4; //default to A4 as per the schematic 
int detectThreshold = 30; // higher values will make this more sensitive. 7 in minimum for objects within 2cm. 30 is about 30 cm   
unsigned long endTime; //Variable for transmit calc.

//these variables are global because of the sensitive timing of the transmit sequence
int objectDetected = 0;    
int numObjectSamples = 0;


COM_MANAGER::COM_MANAGER(int pin){
  transmitPin = pin; //setup transmit out if not default
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
  endTime = micros()+time; //log the time at the start of the pulse
  while(micros()<endTime)  //While we are still in our transmit window
  {
    //This is one full cycle
    //The calibrated delays are not exactly (1/2)period
    //They need to account for the write times and the while calculations
    //Their values need to be found by expweimentation with osciliscope
    digitalWrite(transmitPin, MARK); //write the pin high 
    delayMicroseconds(8);           //calibrated delay. 8 results in a 13uSec high
    digitalWrite(transmitPin, 0);    //write the pin low  
    delayMicroseconds(4);           //calibrated delay. 4 results in a 13uSec low
  }
}

/* Leave pin off for time (given in microseconds) */
void COM_MANAGER::space(int time) {
  // Sends an IR space for the specified number of microseconds.
  // A space is no output, so the PWM output is disabled.
  digitalWrite(transmitPin, SPACE); //set the output to low 
  delayMicroseconds(time);          //delat for the appropriate time
}


//function for transmitting a bit string. 
boolean COM_MANAGER::transmitObjectDetect(unsigned long data, int nbits, int RxPin){

  //Send the initial mark+space fotr handshake 
  markObjectDetect(NEC_HDR_MARK, RxPin);              
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


  if(objectDetected<detectThreshold){  //10 is a threshold value higher values will make this more sensitive
    objectDetected = 0; 
    return 1;
  }
  else{
    objectDetected = 0;
    return 0;
  }

}

void COM_MANAGER::markObjectDetect(int time, int RxPin) {
  // Sends an IR mark for the specified number of microseconds.
  // The mark output is modulated at the PWM frequency.

  endTime = micros()+time; //log the time at the start of the pulse
  while(micros()<endTime)  //While we are still in our transmit window
  {
    //This is one full cycle
    //The calibrated delays are not exactly (1/2)period
    //They need to account for the write times and the while calculations
    //Their values need to be found by expweimentation with osciliscope
    digitalWrite(transmitPin, MARK); //write the pin high 
    delayMicroseconds(3);           //calibrated delay. 8 results in a 13uSec high
    objectDetected += digitalRead(RxPin); //if the light reflected off a wall this will NOTincrement Remeber the sensor is active low
    numObjectSamples++;
    digitalWrite(transmitPin, 0);    //write the pin low  
    delayMicroseconds(5);           //calibrated delay. 4 results in a 13uSec low
  }
}




