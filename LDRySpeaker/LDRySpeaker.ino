// Declaramos las Variables
int positivoDelParlante = 3;  // Donde conectaremos el pin positivo del parlante (speaker)
int sensorLDR = A0;
int valorSensorLDR = 0;
int tempo = 300;

// Esta funcion reproducitTono recibe dos parametros
// Tono y Duracion.
// int nos indica que el parametro es un integer (numero entero)
void reproducirTono(int tono, int duracion) {
  for (long i = 0; i < duracion * 1000L; i += tono * 2) {
    digitalWrite(positivoDelParlante, HIGH);
    delayMicroseconds(tono);
    digitalWrite(positivoDelParlante, LOW);
    delayMicroseconds(tono);
  }
}

void reproducirNota(int nota, int duracion) {
  int tonos[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  reproducirTono(tonos[nota], duracion);

}

void setup() {
  pinMode(positivoDelParlante, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // mapeo el valor del sensorLDR a valores entre 0 y 7, es decir, las notas del array
  valorSensorLDR = map(analogRead(sensorLDR), 3 , 157, 0 , 7); 
  // imprimo el valor en el monitor serial
  Serial.println(valorSensorLDR);
  reproducirNota(valorSensorLDR,500);
  //espera 1 milisegundo antes de tocar la proxima nota
  delay(1);

}
