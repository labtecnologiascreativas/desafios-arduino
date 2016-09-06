// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // crea un objeto "servo" para controlar el servo motor  
                // puede ser creado un máximo de 8 objetos "servo" 
 
int pos = 0;    // en esta variable guardamos la posición del servo motor 
 
void setup() 
{ 
  myservo.attach(9);  // conecta el servo conectado al pin 9 al objeto "servo" 
} 
 
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)  // va de 0 grados a 180 grados 
  {                                  // en pasos de 1 grado 
    myservo.write(pos);              // le dice al servo que vaya a la posición de la 
				     //	variable 'pos' 
    delay(15);                       // espera 15ms hasta que el servo alcance la posicion 
  } 
  for(pos = 180; pos>=1; pos-=1)     // va de 180 grados a 0 grados 
  {                                
    myservo.write(pos);               // le dice al servo que vaya a la posición de la 
				     //	variable 'pos' 
    delay(15);                       // espera 15ms hasta que el servo alcance la posicion 
  } 
} 
