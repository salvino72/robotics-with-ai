// ==========================================
// LEZIONE 7 - PROGETTO SPECIALE FASE 2
// 02: SEGUE-LINEA (3 SENSORI IR) 🛣️
// ==========================================

/*
  In questa esercitazione il robot:
  1. Utilizza 3 sensori IR posizionati sotto lo chassis.
  2. Rileva il riflesso della luce sulla superficie.
  3. Cerca di mantenere la riga nera tra i sensori per restare in pista.
*/

// Definizione Pin Motori (Shield V4.0)
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

// Definizione Pin Sensori Linea (Basato su Elegoo V4.0 standard)
#define LINE_S_LEFT   10
#define LINE_S_CENTER 2
#define LINE_S_RIGHT  4

// Valori Digitali: 0 = Vedo nero (linea), 1 = Vedo Bianco (pavimento)
int leftState, centerState, rightState;

void setup() {
  Serial.begin(9600);
  
  // Setup Motori
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Setup Sensori Linea
  pinMode(LINE_S_LEFT, INPUT);
  pinMode(LINE_S_CENTER, INPUT);
  pinMode(LINE_S_RIGHT, INPUT);
}

void loop() {
  // Lettura stato sensori (0=LINEA NERA, 1=BIANCO)
  leftState   = digitalRead(LINE_S_LEFT);
  centerState = digitalRead(LINE_S_CENTER);
  rightState  = digitalRead(LINE_S_RIGHT);
  
  // LOGICA DI CONTROLLO
  // Caso 1: Solo il centrale vede la linea -> Vai dritto
  if (centerState == LOW && leftState == HIGH && rightState == HIGH) {
    moveForward(180);
  }
  // Caso 2: Sinistro e centrale vedono la linea -> Gira a sinistra dolcemente
  else if (leftState == LOW && rightState == HIGH) {
    turnLeft(200);
  }
  // Caso 3: Destro e centrale vedono la linea -> Gira a destra dolcemente
  else if (rightState == LOW && leftState == HIGH) {
    turnRight(200);
  }
  // Caso 4: Nessuno vede la linea (forse curva troppo stretta) -> Fermati o cerca
  else if (leftState == HIGH && centerState == HIGH && rightState == HIGH) {
    stopRobot();
  }
}

// --- Funzioni di Movimento ---
void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void turnRight(int speed) {
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // Ruota verso destra
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); // Ruota verso sinistra
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}
