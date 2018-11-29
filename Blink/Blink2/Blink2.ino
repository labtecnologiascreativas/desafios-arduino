/*
  Blink
  Prende un LED por un segundo, luego lo apaga por otro segundo, y lo repite. 
  Este código de ejemplo es de dominio público
 */
 
// El Pin 13 tiene un LED conectado en la mayoría de las placas Arduino
// Le ponemos un nombre, en este caso "led":
int ledVerde = 5;
int ledRojo = 4;
int ledAzul = 3;
int ledAmarillo = 2;

// Aqui escribimos la rutina inicial:
void setup() {                
  // inicializamos el pin como salida (OUTPUT en inglés)
  pinMode(ledVerde, OUTPUT);   
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);  
}

void parpadear(int led, int tiempoPrendido, int tiempoApagado) {
  digitalWrite(led, HIGH);   // Prende el LED (HIGH es "prendido")
  delay(tiempoPrendido);               // espera un segundo
  digitalWrite(led, LOW);    // apaga el LED (LOW es "apagado")
  delay(tiempoApagado);               // espera un segundo
}

// Aquí escribimos lo que se va a repetir:
void loop() {
  parpadear(ledVerde, 250, 250);
  parpadear(ledRojo, 250, 250);
  parpadear(ledAzul, 250, 250);
  parpadear(ledAmarillo, 250, 250);
}
