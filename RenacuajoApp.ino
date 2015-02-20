/* Vehiculo controlado por APP
 Programa para controlar vehiculo desde APP movido por servomotores
 Creado por Jose Pujol y Alberto Pumar
 */


// conexiones pines
const int servoLPin = 4; // Pin Sevomotor Izquierdo
const int servoRPin=7;   // Pin Sevomotor Derecho

const int buzzerPin =  10;
const int ledPinR = 6;
const int ledPinG = 5;
const int ledPinB = 9;


// Variables de comunicacion:

int incomingByte; //// variable para almacenar los datos 
                      // que entran por el puerto serie 

void setup() {
  pinMode (servoRPin, OUTPUT);
  pinMode (servoLPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  Serial.begin(9600); //Establece conexión con el puerto serie
}
void go_forward(){ //Rutina para que el coche avance
  //gira adelante
  digitalWrite(servoRPin,HIGH);
  digitalWrite(servoLPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(servoRPin,LOW);
  delayMicroseconds(1000);
  digitalWrite(servoLPin,LOW);
  delayMicroseconds(18000);
}
void go_back(){ //Rutina para que el coche retroceda
  digitalWrite(servoRPin,HIGH);
  digitalWrite(servoLPin,HIGH);
  delayMicroseconds(1000);// 1 - 1500 atras, de 1500 a 3000 delante 
  digitalWrite(servoLPin,LOW);
  delayMicroseconds(1000);
  digitalWrite(servoRPin,LOW);
  delayMicroseconds(18000);
}
void turn_left(){ //Rutina para que el coche gire a la derecha
  digitalWrite(servoRPin,HIGH);
  digitalWrite(servoLPin,HIGH);
  delayMicroseconds(2000);// 1 - 1500 atras, de 1500 a 3000 delante 
  digitalWrite(servoRPin,LOW);
  digitalWrite(servoLPin,LOW);
  delayMicroseconds(18000);
}
void turn_right(){ //Rutina para que el coche gire a la izquierda
  digitalWrite(servoRPin,HIGH);
  digitalWrite(servoLPin,HIGH);
  delayMicroseconds(1000);// 1 - 1500 atras, de 1500 a 3000 delante 
  digitalWrite(servoRPin,LOW);
  digitalWrite(servoLPin,LOW);
  delayMicroseconds(19000);
}
void parar(){ //Rutina para que el cohe pare
  digitalWrite(servoRPin,LOW);
  digitalWrite(servoLPin,LOW);
}
void loop() {
//Si hay datos puerto serie
  if (Serial.available() > 0) { 
    incomingByte = Serial.read(); //Acumula el último byte en incomingByte
  }
  if (incomingByte == 'f') { //SI es “f” (botón de arriba)  
    go_forward(); //Va hacia alante 
  }
  if (incomingByte == 'b') { //Si es “b” (botón de abajo),
    go_back(); //Va hacia atrás
  }
  if (incomingByte == 'r') { //Si es “r” (botón de la derecha);
    turn_right(); //Gira a la derecha
  }
  if (incomingByte == 'l') { //Si es “l” (botón de la izquierda), 
    turn_left(); //Gira a la izquierda
  }
  if (incomingByte == 's') { //Si es “s”  (al sotar cualquier boton),
    parar();  //El coche se para.
  }

} 
