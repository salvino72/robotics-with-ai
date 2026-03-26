/*
  Progetto 04: Controllo Velocità PWM per Curve Fluide
  In questo sketch utilizziamo segnali PWM per regolare la velocità di ogni singola 
  ruota del robot, creando una curva fluida con raggi diversi.
*/

// Pin di controllo per il Motore Sinistra
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10; 

// Pin di controllo per il Motore Destra
const int IN3 = 6;
const int IN4 = 7;
const int ENB = 5; 

void setup() {
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Controllo Velocità PWM...");
}

void loop() {
  // Esempio 1: Curva ampia a destra
  // Ruota sinistra più veloce (150) della destra (50)
  Serial.println("Avanti - Curva ampia verso destra");
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, 150);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, 50);
  delay(3000);
  
  // Esempio 2: Accelerazione lineare
  // Aumenta la velocità di entrambe le ruote gradualmente
  Serial.println("Avanti - Accelerazione lineare");
  for(int v = 0; v <= 255; v++){
    analogWrite(ENA, v);
    analogWrite(ENB, v);
    delay(20);
  }
  
  // Esempio 3: Decelerazione
  Serial.println("Avanti - Decelerazione");
  for(int v = 255; v >= 0; v--){
    analogWrite(ENA, v);
    analogWrite(ENB, v);
    delay(20);
  }

  // Stop
  Serial.println("Stop.");
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(3000);
}
