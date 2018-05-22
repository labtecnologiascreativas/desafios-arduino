// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

// Incluimos la librería
#include <AFMotor.h>

// Crea el objeto Motor y selecciona el 'puerto' ('port' en inglés) M1, M2, M3 or M4. En este caso, M1
AF_DCMotor motor(1);

void setup() {
  // Definimos la velocidad para el motor
  motor.setSpeed(200);
 // Prendemos el motor
  motor.run(RELEASE);
}

void loop() {
  uint8_t i;

  // El motor avanza (FORWARD) 
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  // El motor retrocede (BACKWARD)
  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }

}
