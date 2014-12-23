// Author = Nicholas Lantz
// Email = Nicholaslantz@gmail.com
// Date = 21Dec2014

//This code is the entry point for the Swarm Vehicle software
//as part of the Autonomous Swarm Transport System


//include your libraries 
#include "COM_MANAGER.h"

//Define pins 
const int TRANSMIT_PIN = A4;
const int RX_PIN_0 = A0;
//const int RX_PIN_90 = A0;
//const int RX_PIN_180 = A0;
//const int RX_PIN_270 = A0;


//define values for later use
unsigned long data = B11111111;
int numBits = 8;

void setup()
{
  Serial.begin(9600); //initiate connection with computer
  
  //define pinmodes
  pinMode(TRANSMIT_PIN, OUTPUT);
  pinMode(RX_PIN_0, INPUT);
  
  COM_MANAGER cm(TRANSMIT_PIN);   //instantiate a communications manager 
  
  //loop section here. Just because thats how I roll
  while(1)
  {
      //cm.transmitObjectDetect(data, numBits, RX_PIN_0);
  }

}


void loop(){}


