// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

// Incluimos la librería
#include <AFMotor.h>

// Crea los objetos Motor y selecciona el 'puerto' ('port' en inglés) M1, M2, M3 o M4.
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Definimos las velocidades para los motores
  motor1.setSpeed(100);
  motor2.setSpeed(255);
  motor3.setSpeed(150);
  motor4.setSpeed(175);
  
 // Prendemos los motores
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(500);
}
