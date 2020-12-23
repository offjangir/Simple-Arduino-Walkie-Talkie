#include <RF24.h>
#include <SPI.h>
#include <RF24Audio.h>
#include "printf.h"   
// loading libraries  Libraries include RF24 and RF 24 Audio Libraries
RF24 rad(12,13); // Pins for RF24 Radio   
RF24Audio rfAudio(rad,0); 
void setup() {      
  // Setting up the radio and Serial transmission
  Serial.begin(115200);
  printf_begin();
  rad.begin();
  rad.printDetails();
  
  rfAudio.receive();//default state for recieveing 
  rfAudio.begin();
}
   
void loop()
{ // for direct transmission,no button intruppt for digital pin 
 rfAudio.transmit();
}

/* THE CODE BELOW IS FOR A DIGITAL BUTTON (IF USED IN THE CIRCUIT) */ 
/* 
void setup() {      
  // Setting up the radio and Serial transmission
  Serial.begin(115200);
  printf_begin();
  rad.begin();
  rad.printDetails();
  pinMode(tranmission, INPUT);
  rfAudio.begin();
  //checking if button is pressed
  attachInterrupt(digitalPinToInterrupt(transmission), trans, CHANGE)
  rfAudio.receive(); // for direct transmission,no button intruppt for digital pin
}
   
void loop()
{
 if (digitalRead(transmission)) rfAudio.transmit();
  else rfAudio.receive();
}
*/ 
