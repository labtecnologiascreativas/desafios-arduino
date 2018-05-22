#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Crea el objeto motor shield
// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Selecciona el 'puerto' ('port' en inglés) M1, M2, M3 or M4. En este caso, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(2);
// También podés poner otro motor en el puerto M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

void setup() {
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Indica la velocidad para comenzar, de 0 (off) a 255 (max velocidad)
  myMotor->setSpeed(150);
  myMotor->run(FORWARD);
  // prende el motor
  myMotor->run(RELEASE);
}

void loop() {
  uint8_t i;
  
  myMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  
  myMotor->run(BACKWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }

  myMotor->run(RELEASE);
  delay(1000);
}
