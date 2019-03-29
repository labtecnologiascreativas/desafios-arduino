/*
  Blink 2
  Parpadea varios leds de forma sequencial utilizando una funcion.
  Este código de ejemplo es de dominio público
 */

/* Vamos a utilizar los pins 2, 3, 4 y 5.
   Le ponemos un nombre a cada uno, para identificarlos en el código.
   De esta forma, cuando hagamos referencia a "ledVerde" hablamos del pin 5.
*/

int ledVerde = 5;
int ledRojo = 4;
int ledAzul = 3;
int ledAmarillo = 2;

// Aqui escribimos la rutina inicial:
void setup() {
  // inicializamos los pins como salida (OUTPUT en inglés)
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
}

/*
  Vamos a utilizar una funcion de forma tal de poder reutilizar el codigo.
  Nuestra funcion recibira 3 parametros:
  - El led que queremos hacer parpadear
  - Cuanto tiempo dura encendido (milisegundos)
  - Cuanto tiempo dura apagado (milisegundos)
  De esta forma podemos llamar a la misma funcion con diferentes parametros para obtener diferentes resultados.
  Si no utilizaramos esta funcion, deberiamos repetir las 4 lineas de codigo por cada led.
*/
void parpadear(int led, int tiempoPrendido, int tiempoApagado) {
  digitalWrite(led, HIGH);   // Prende el LED (HIGH es "prendido")
  delay(tiempoPrendido);               // espera un segundo
  digitalWrite(led, LOW);    // apaga el LED (LOW es "apagado")
  delay(tiempoApagado);               // espera un segundo
}

// Aquí escribimos lo que se va a repetir:
// Vamos a llamar a nuestra funcion "parpadear" variando el parametro LED cada vez.
void loop() {
  parpadear(ledVerde, 250, 250);
  parpadear(ledRojo, 250, 250);
  parpadear(ledAzul, 250, 250);
  parpadear(ledAmarillo, 250, 250);
}
