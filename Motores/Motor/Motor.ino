#include <MotorShield.h>

const int ledPin = 13;
MS_DCMotor motor(MOTOR_B);

void setup() {
  pinMode(ledPin,OUTPUT);
  
  motor.run(BRAKE);
  motor.setSpeed(255);
}

void loop() {
  motor.run(BACKWARD|RELEASE);
  delay(3000);
  motor.run(BRAKE);
  
  delay(1000);
    
  motor.run(FORWARD|RELEASE);
  delay(3000);
  motor.run(BRAKE);
}

