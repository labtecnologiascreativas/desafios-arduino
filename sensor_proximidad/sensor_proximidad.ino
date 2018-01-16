 /*
  Basado en el sketch Ping))) Sensor, de David A. Mellis (http://www.arduino.cc/en/Tutorial/Ping)

  El sensor emite un pulso ultrasónico que luego es recibido y leído por el mismo, 
  de esa manera podemos calcular la distancia de un objeto.
  
*/

// las "constantes" no cambian, su usan aquí para
// definir los numeros de pin:
const int pingPin = 7;

void setup() {
  // inicializamos la comunicación del puerto Serial:
  Serial.begin(9600);
}

void loop() {
  // establecemos las variables para la duracion del pulso y la distancia resultante
  // en centímetros:
  long duration,cm;

  // el pulso HIGH es disparado por 5 microsegundos
  // antes enviamos un pulso LOW para asegurarnos un pulso HIGH claro
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // El mismo pin es usado para leer la señal de vuelta: un pulso HIGH cuya duración
  // es el tiempo que le lleva alcanzar un objeto y volver
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convertimos el tiempo a distancia (microsegundos a centímetros)
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  // La velocidad del sonido es 349 m/s, o 29 microsugundos/centímetro
  // El pulso viaja ida y vuelta, por lo tanto para obtener la distancia 
  // al objeto, debemos tomar la mitad de la distancia recorrida
  return microseconds / 29 / 2;
}
