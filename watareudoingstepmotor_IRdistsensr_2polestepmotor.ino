//Stepper motor base code using 2 bipolar motors and IR distance sensor for light:canopy distance control
#include <DistanceGP2Y0A21YK.h>

DistanceGP2Y0A21YK Dist;
DistanceGP2Y0A21YK Dist2;
int comparison;

int distanceM34;

int distanceIR1;
int distanceIR2;

#define DIR_PIN 4
#define STEP_PIN 6

#define DIR_PIN2 3
#define STEP_PIN2 5

void setup() { 
  pinMode(DIR_PIN, OUTPUT); 
  pinMode(STEP_PIN, OUTPUT); 
  pinMode(DIR_PIN2, OUTPUT); 
  pinMode(STEP_PIN2, OUTPUT); 
  Serial.begin(9600);
  Dist.begin(A0); //We are using analogue pin 0 for one IR sensor
  Dist2.begin(A1); //We are using analogue pin 1 for one IR sensor
  
  distanceM34 = 0;
} 

void loop(){ 
  comparison = distanceIR1 - distanceIR2;
  
  if(comparison > (distanceIR1 / distanceIR2) * 0.25){
    rotateM34(distanceM34 * -1, 0.1);  
  }
    
  if(distanceIR1 > 10 && distanceIR1 < 70){
    //rotate a specific number of degrees
    rotateM34((1600*3), 0.1);
    distanceM34 = distanceM34 + (1600*3);
  }
  
}

void rotateM2(int steps, float speed){ 
  //rotate a specific number of microsteps (8 microsteps per step) - (negative for reverse)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);

  digitalWrite(DIR_PIN,dir); 

  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN, HIGH);   
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(usDelay); 
  } 
}

void rotateM34(int steps, float speed){ 
  //rotate a specific number of microsteps (8 microsteps per step) - (negative for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);
  digitalWrite(DIR_PIN2,dir); 

  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN2, HIGH);  
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN2, LOW); 
    delayMicroseconds(usDelay); 
  } 
}
