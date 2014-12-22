// Author = Nicholas Lantz
// Email = Nicholaslantz@gmail.com
// Date = 21Dec2014

//This code is the entry point for the Swarm Vehicle software
//as part of the Autonomous Swarm Transport System


//include your libraries 
#include "COM_MANAGER.h"

//Define pins 
const int TRANSMIT_PIN = A4;
const int RX_PIN = A0;


//define values for later use
unsigned long data = B11111111;
int numBits = 8;

void setup()
{
  Serial.begin(9600); //initiate connection with computer
  
  //define pinmodes
  pinMode(TRANSMIT_PIN, OUTPUT);
  pinMode(RX_PIN, INPUT);
  
  COM_MANAGER cm(TRANSMIT_PIN);   //instantiate a communications manager 
  
  while(1)
  {
      Serial.println(cm.transmitObjectDetect(data, numBits, RX_PIN));
  }

}

void loop()
{

}


