
// Incluimos la libreria Tone (Tono en ingles), que nos permite generar tonos musicales muy facilmente.
#include <Tone.h>

// Inicializamos la libreria Tone, creando un objeto llamado generadorDeTonos
Tone generadorDeTonos;

// Declaramos las Variables
int parlante = A0;  // Donde conectaremos el pin positivo del parlante (speaker)
int sensorLDR = A1; // Donde conectaremos el sensor LDR.
int valorSensorLDR = 0; // Almacena el ultimo valor leido del sensor.
int notaAReproducir = 0;// Almacen el ultimo valor de nota a reproducir.
int tempo = 300; // Tiempo de espera entre una nota y la siguiente.
// Vamos a armar un Array, que se diferencia del resto de las variables que vimos antes, por contener no uno, sino varios valores.
// Para indicar que nuestra variable es un array, le agregamos los corchetes ("[]") al final del nombre.
// Nuestro array va a contener 7 notas, DO, RE, MI, FA, SOL, LA y SI.
// Para mas informacion sobre como funciona la libreria tone: https://github.com/bhagman/Tone
int arrayDeNotas[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4 };

void setup() {
  // Inicializamos el generadorDeTonos, indicando en que pin conectamos el parlante.
  generadorDeTonos.begin(parlante);
  Serial.begin(9600);
}

void loop() {
  // Leo el sensorLDR y guardo el valor en la variable
  valorSensorLDR = analogRead(sensorLDR);
  // imprimo el valor en el monitor serial
  Serial.println(valorSensorLDR);
  
  // mapeo el valor del sensorLDR a valores entre 0 y 7, es decir, la cantidad de notas en el arrayDeNotas.
  notaAReproducir = map(valorSensorLDR, 380 , 980, 0 , 7); 

  // Si el sensor mide mas de 390
  if (valorSensorLDR > 380) {
    // Le decimos al generadorDeTonos que reproduzca la nota correspondiente.
    generadorDeTonos.play(arrayDeNotas[notaAReproducir]);  
  } else {
    // sino, le decimos que haga silencio.
    generadorDeTonos.stop();
  }
  
  
  //esperamos antes de tocar la proxima nota
  delay(tempo);
}
