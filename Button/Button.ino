/*
  Button ("Botón")


 Prende y apaga un LED (Diodo Emisor de Luz) conectado al pin digital 13,
 cuando se presiona el botón pulsador conectado al pin 2.

 El Circuito:
 * Un LED conectado al pin 13 y a tierra (gnd)
 * Un botón pulsador conectado al pin 2 y a +5V
 * Una resistencia de 10k conectada al pin 2 y a tierra (gnd)


 creado en 2005
 por DojoDave <http://www.0j0.org>
 modificado el 30 Aug 2011
 por Tom Igoe

 Este código de ejemplo es de dominio público

 http://www.arduino.cc/en/Tutorial/Button
 */

// las "constantes" no cambian, su usan aquí para
// definir los numeros de pin:
const int buttonPin = 2;     // el numero de pin del botón pulsador
const int ledPin =  13;      // el numero de pin del LED

// las "variables" cambian:
int buttonState = 0;         // variable para leer el estado del botón

void setup() {
  // inicializa el pin del LED como salida (OUTPUT):
  pinMode(ledPin, OUTPUT);
  // inicializa el pin del botón pulsador como entrada (INPUT):
  pinMode(buttonPin, INPUT);
}

void loop(){
  // lee el estado del botón pulsador:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
