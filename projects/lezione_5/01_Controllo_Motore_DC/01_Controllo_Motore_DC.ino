/*
  Progetto 01: Controllo Motore DC con Driver L298N
  Questo sketch permette di controllare un motore in avanti, indietro e fermarlo.
*/

// Definizione dei pin di controllo per il Driver L298N (Esempio per un motore)
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10; // Pin PWM per il controllo della velocità

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Avvio Controllo Motore DC...");
}

void loop() {
  // Avanti
  Serial.println("Motore Avanti");
  forward(200); // Velocità tra 0 e 255
  delay(2000);
  
  // Stop
  Serial.println("Motore Stop");
  stopMotor();
  delay(1000);
  
  // Indietro
  Serial.println("Motore Indietro");
  backward(200);
  delay(2000);
  
  // Stop
  Serial.println("Motore Stop");
  stopMotor();
  delay(3000);
}

void forward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

void backward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}
