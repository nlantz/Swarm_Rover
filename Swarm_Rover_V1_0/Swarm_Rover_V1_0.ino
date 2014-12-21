// Author = Nicholas Lantz
// Email = Nicholaslantz@gmail.com
// Date = 21Dec2014

//This code is the entry point for the Swarm Vehicle software
//as part of the Autonomous Swarm Transport System

//    This section is example reference on how to implement a class
//    #include "LED13.h"
//     
//    LED13 led;//initialize an instance of the class
//     
//    void setup(){/*nothing to setup*/}
//     
//    void loop(){
//      led.blink(500);//stay one second on, then a second off
//    }

//include your libraries 
#include "COM_MANAGER.h"

//Define pins 
const byte TRANSMIT_PIN = A4;


void setup()
{
  //define pinmodes
  pinMode(TRANSMIT_PIN, OUTPUT);
}

void loop()
{
 
}


