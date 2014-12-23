// Author = Nicholas Lantz
// Email = Nicholaslantz@gmail.com
// Date = 21Dec2014

//This code is the entry point for the Swarm Vehicle software
//as part of the Autonomous Swarm Transport System


//include your libraries 
#include "COM_MANAGER.h"

//define values for later use
unsigned long data = B11111111;
int numBits = 8;

void setup()
{
  //initiate connection with computer
  Serial.begin(9600);
    
  //instantiate a communications manager 
  COM_MANAGER cm();   
  
  //loop section here. Just because thats how I roll
  while(1)
  {
      //cm.transmitObjectDetect(data, numBits, RX_PIN_0);
  }

}


void loop(){}


