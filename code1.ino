
#include "AccelStepper.h"


#define motorInterfaceType 1


const int dirPin  = 7;
const int stepPin = 6;
const int enPin   = 8;

const int limit = 2;

int state = 1;
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(limit,INPUT);
  pinMode(enPin,OUTPUT);
 
  stepper.setMaxSpeed(1000);
  stepper.setCurrentPosition(0);



}

void loop() {
 

  switch(state){
    case 0:; // idle state
    break;
    case 1: runStepper();
    break;
  
  }
  delay(30);

}

void runStepper(){
     bool b = false;
     while( !b )
     {
        if( digitalRead(limit) == 0){
           stepper.setCurrentPosition(0);
           delay(2000);
           state = 0;
           break;
        }
        stepper.setSpeed(1500);
        stepper.runSpeed();
     }
}
