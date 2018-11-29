/*
  Blink
  Prende un LED por un segundo, luego lo apaga por otro segundo, y lo repite. 
  Este código de ejemplo es de dominio público
 */
 
// El Pin 13 tiene un LED conectado en la mayoría de las placas Arduino
// Le ponemos un nombre, en este caso "led":
int led = 13;

// Aqui escribimos la rutina inicial:
void setup() {                
  // inicializamos el pin como salida (OUTPUT en inglés)
  pinMode(led, OUTPUT);     
}

// Aquí escribimos lo que se va a repetir:
void loop() {
  digitalWrite(led, HIGH);   // Prende el LED (HIGH es "prendido")
  delay(1000);               // espera un segundo
  digitalWrite(led, LOW);    // apaga el LED (LOW es "apagado")
  delay(2000);               // espera un segundo
}
