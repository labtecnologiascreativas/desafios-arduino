 /*
  
  El sensor emite un pulso ultrasónico que luego es recibido y leído por el mismo, 
  de esa manera podemos calcular la distancia de un objeto.
  
*/

// las "constantes" no cambian, su usan aquí para
// definir los numeros de pin:
const int trigPin = 8;
const int echoPin= 7;

void setup() {
  // inicializamos la comunicación del puerto Serial:
  Serial.begin(9600);
  // Establecemos el modo del pin "trigger" como salida (OUTPUT)
  pinMode(trigPin, OUTPUT);
  // Establecemos el modo del pin "echo" como entrada (INPUT)
  pinMode(echoPin, INPUT);

}

void loop() {
  // establecemos las variables para la duracion del pulso y la distancia resultante
  // en centímetros:
  long duration,cm;

  // el pulso HIGH es disparado por 5 microsegundos
  // antes enviamos un pulso LOW para asegurarnos un pulso HIGH claro
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // El pin "echo" es usado para leer la señal de vuelta: un pulso HIGH cuya duración
  // es el tiempo que le lleva alcanzar un objeto y volver
  duration = pulseIn(echoPin, HIGH);

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
