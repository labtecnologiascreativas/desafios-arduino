#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Crea el objeto motor shield
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Selecciona el 'puerto' ('port' en inglés) M1, M2, M3 or M4. En este caso, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

void setup() {
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Indica la velocidad para comenzar, de 0 (off) a 255 (max velocidad)
  myMotor1->setSpeed(25);
  myMotor2->setSpeed(50);
  myMotor3->setSpeed(75);
  myMotor4->setSpeed(100);
  
//  myMotor1->run(FORWARD);
//  myMotor2->run(FORWARD);
//  myMotor3->run(FORWARD);
//  myMotor4->run(FORWARD);
  // prende el motor
  myMotor1->run(RELEASE);
  myMotor2->run(RELEASE);
  myMotor3->run(RELEASE);
  myMotor4->run(RELEASE);
}

void loop() {
  myMotor1->run(FORWARD);
  myMotor2->run(FORWARD);
  myMotor3->run(FORWARD);
  myMotor4->run(FORWARD);
  delay(1000);
}
