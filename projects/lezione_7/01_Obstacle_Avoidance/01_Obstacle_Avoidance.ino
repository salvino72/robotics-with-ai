// ==========================================
// LEZIONE 7 - PROGETTO SPECIALE FASE 2
// 01: EVITAMENTO OSTACOLI (HC-SR04 + SERVO)
// ==========================================

/*
  In questa esercitazione il robot:
  1. Si muove dritto.
  2. Se vede un ostacolo (< 25 cm), si ferma.
  3. Il servo ruota il sensore a Destra e Sinistra.
  4. Misura la distanza nelle due direzioni.
  5. Sceglie la direzione più libera e riparte.
*/

#include <Servo.h>

// Definizione Pin Motori (In base alla Shield Elegoo V4.0)
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

// Definizione Pin HC-SR04
#define ECHO_PIN A4
#define TRIG_PIN A5

// Definizione Pin Servo
#define SERVO_PIN 3

Servo myservo;
int distance = 0;
int rightDistance = 0;
int leftDistance = 0;

void setup() {
  Serial.begin(9600);
  
  // Setup Motori
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Setup Sensore Ultrasuoni
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  
  // Setup Servo
  myservo.attach(SERVO_PIN);
  myservo.write(90); // Guarda dritto
  delay(1000);
}

void loop() {
  distance = readDistance();
  
  if (distance > 25) {
    moveForward();
  } else {
    stopRobot();
    delay(500);
    lookRightAndLeft();
    
    if (rightDistance > leftDistance) {
      turnRight();
      delay(500);
    } else {
      turnLeft();
      delay(500);
    }
    stopRobot();
    delay(200);
  }
}

// --- Funzioni di Controllo ---

int readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  int d = (duration * 0.034) / 2;
  return d;
}

void lookRightAndLeft() {
  myservo.write(10); // Guarda a destra
  delay(500);
  rightDistance = readDistance();
  
  myservo.write(170); // Guarda a sinistra
  delay(500);
  leftDistance = readDistance();
  
  myservo.write(90); // Torna al centro
  delay(500);
}

// --- Movimenti ---
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}
