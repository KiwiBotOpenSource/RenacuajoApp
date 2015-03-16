/*
VEHÍCULO CONTROLADO POR APP
Programa para control de printbot kiwibot por APP y HC06.
Desarrollado por Miguel Granero, Jose Pujol y Alberto Pumar.
Marzo 2015
*/

// LEDS
const int ledPinR = 6;
const int ledPinG = 5;
const int ledPinB = 9;

//Timbre
const int buzzerPin = 10;

//Pines de los servos
const int M7 = 7;
const int M4 = 4;

// lee el puerto serial
int ch;

//Memoria
int memory;

void setup() {
  Serial.begin(9600);
  pinMode(M7, OUTPUT);
  pinMode(M4, OUTPUT);
}

void backward() {
  digitalWrite(M4, HIGH);
  digitalWrite(M7, HIGH);
  delayMicroseconds(1000);
  digitalWrite(M4, LOW);
  delayMicroseconds(1000);
  digitalWrite(M7, LOW);
  delayMicroseconds(18000);
}

void frontwards() {
  digitalWrite(M7, HIGH);
  digitalWrite(M4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(M7, LOW);
  delayMicroseconds(1000);
  digitalWrite(M4, LOW);
  delayMicroseconds(18000);
}

void left(){
  digitalWrite(M7, HIGH);
  digitalWrite(M4, HIGH);
  delayMicroseconds(2000);
  digitalWrite(M7, LOW);
  digitalWrite(M4, LOW);
  delayMicroseconds(18000);
}

void right(){
  digitalWrite(M7, HIGH);
  digitalWrite(M4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(M7, LOW);
  digitalWrite(M4, LOW);
  delayMicroseconds(19000);
}

void stopA() {
  digitalWrite(M7, LOW);
  digitalWrite(M4, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    ch = Serial.read(); // Fijamos la variable ch a lo que lea en el serial
}
//Asociamos la memoria a estos codigos que indican la direccion del motor
  if (ch == 'S') { 
    memory = 'S';
  }
  if (ch == 'l') {
    memory = 'l';
  }
  if (ch == 'r') {
    memory = 'r';
  }
  if (ch == 'b') {
    memory = 'b'; 
  }
  if (ch == 's') {
    memory = 's';
  }
  
//Aqui hacemos con los motores lo que hayamos recibido por el serial, como hemos fijado arriba
  if (memory == 's') {
    stopA();
  }
  if (memory == 'f') {
    frontwards();
  }
  if (memory == 'l') {
    left();
  }
  if (memory == 'b') {
    backward();
  }
  if (memory == 'r') {
    right();
  }
  //Aqui encendemos totalmente los LEDs
   if (ch == 'H') {
    analogWrite(ledPinR, 255);
    analogWrite(ledPinG, 255);
    analogWrite(ledPinB, 255);
  }
//Aqui apagamos los LEDs 
  if (ch == 'L') {
    analogWrite(ledPinR, 0);
    analogWrite(ledPinG, 0);
    analogWrite(ledPinB, 0);
  }
//En los proximos 2 bloques encendemos o apagamos el timbre
  if (ch == 'Z') {
    digitalWrite(buzzerPin, HIGH);//Estos para el timbre
  }
  if (ch == 'z') {
    digitalWrite(buzzerPin, LOW);
  }
  delay(15);
}
