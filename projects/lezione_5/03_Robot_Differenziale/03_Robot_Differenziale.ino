/*
  Progetto 03: Robot con Trazione Differenziale (L298N)
  Questo sketch crea un sistema di controllo per un telaio a 2 ruote per 
  andare dritto, girare a destra o sinistra e fermarsi.
*/

// Pin di controllo per il Motore A (Sinistra)
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10; 

// Pin di controllo per il Motore B (Destra)
const int IN3 = 6;
const int IN4 = 7;
const int ENB = 5; 

void setup() {
  // Impostiamo tutti i pin come uscite
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Robot Pronto!");
}

void loop() {
  // Avanti
  Serial.println("Avanti...");
  avanti(150);
  delay(2000);
  
  // Svolta a Sinistra
  Serial.println("Svolta a Sinistra...");
  svoltaSinistra(150);
  delay(1000);
  
  // Svolta a Destra
  Serial.println("Svolta a Destra...");
  svoltaDestra(150);
  delay(1000);
  
  // Stop e Attesa
  Serial.println("Stop.");
  fermati();
  delay(3000);
}

// Funzioni di movimento
void avanti(int velocita) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocita);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocita);
}

void svoltaSinistra(int velocita) {
  // Ruota destra avanti, Ruota sinistra indietro
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocita);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocita);
}

void svoltaDestra(int velocita) {
  // Ruota sinistra avanti, Ruota destra indietro
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocita);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velocita);
}

void fermati() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
