/*
 * Este es un ejemplo de uso básico de un LED RGB de Ánodo común.
 * Imaginemos un led RGB como la sumatoria de 3 leds individuales.
 * En un led normal tenemos 2 pins, uno positivo y otro negativo.
 * Ahora en lugar de tener cada led su pin "positivo" y su pin "negativo",
 * comparten entre los 3 el "positivo" y cada color tiene su correspondiente pin "negativo".
 * Para que el led se encienda, debemos conectar el pin común a 5v,
 * y luego dependiendo de a que pin NO le enviemos voltaje, sera el color del que se enciende el led.
 * En este caso, el pin común se conecta a 5V, por que se trata de un led Ánodo Común.
 * Podríamos estar utilizando un led de Cátodo Común, en cuyo caso, el pin común va conectado a tierra (GND),
 * en cuyo caso, el esquemático debe ser reconsiderado.
 */ 
 
int colorLed = 0;
int tiempoEspera = 1000; // Este es el tiempo que vamos a esperar entre color y color.
int red = 13; // Este es el numero del pin que conectaremos al pin rojo (red) del LED.
int green = 12; // Este es el numero del pin que conectaremos al pin verde (green) del LED.
int blue = 11; // Este es el numero del pin que conectaremos al pin azul (blue) del LED.

void setup() { // Acá indicamos que los pins red, green y blue, son pins de salida (OUTPUT)
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  colorLed = random(7); // random (aleatorio en ingles) es una funcion que devuelve un numero al azar, entre 0 y X.
  
  switch (colorLed) {
    case 0: // si el  colorLed es 0 entonces prendemos rojo
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
    break;
    
    case 1: // si el  colorLed es 1 entonces prendemos verde
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(blue, HIGH);
    break;
    
    case 2: // si el  colorLed es 2 entonces prendemos azul
      digitalWrite(blue, LOW);
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
    break;
    
    case 3: // si el  colorLed es 3 entonces prendemos amarillo
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
    break;
    
    case 4: // si el  colorLed es 4 entonces prendemos  cyan
      digitalWrite(blue, 0);
      digitalWrite(green, 0);
      digitalWrite(red, HIGH);
    break;
    
    case 5: // si el  colorLed es 5 entonces prendemos  magenta
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
    break;
    
    case 6: // si el  colorLed es 6 entonces prendemos  blanco
      digitalWrite(blue, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
    break;
  }
  delay(tiempoEspera);
}
