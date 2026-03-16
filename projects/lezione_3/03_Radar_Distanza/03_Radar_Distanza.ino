/*
 * Lezione 3 - Esercizio 3: Radar di Prossimita'
 * --------------------------------------------
 * Obiettivo: Misurare la distanza con gli ultrasuoni e fornire un feedback sonoro.
 * Simula il comportamento di un sensore di parcheggio.
 */

// Definizione PIN per HC-SR04
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
// Definizione PIN per il Buzzer
const int BUZZER_PIN = 6;

// Variabili per il calcolo della distanza
long durata;
int distanza;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Il Trig invia il segnale
  pinMode(ECHO_PIN, INPUT);  // L'Echo riceve il rimbalzo
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("--- Radar HC-SR04 Attivo ---");
}

void loop() {
  // Pulizia del PIN Trig
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Invio di un impulso di 10 microsecondi
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Lettura della durata del viaggio dell'impulso (microsecondi)
  durata = pulseIn(ECHO_PIN, HIGH);

  // Calcolo della distanza in cm
  // Velocità del suono = 0.034 cm/microsecondo. 
  // Dividiamo per 2 perche' l'onda va e torna.
  distanza = durata * 0.034 / 2;

  // Stampa della distanza per debug
  Serial.print("Distanza: ");
  Serial.print(distanza);
  Serial.println(" cm");

  // Logica del Sensore di Parcheggio:
  // Se l'oggetto è vicino (meno di 30cm), emettiamo suoni intermittenti
  if (distanza > 0 && distanza < 30) {
    // Il "delay" dell'intermittenza dipende dalla distanza
    // Piu' siamo vicini, piu' il bip è veloce.
    int attesa = map(distanza, 2, 30, 50, 500);
    
    tone(BUZZER_PIN, 1000); // Suono a 1kHz
    delay(50);              // Durata del bip
    noTone(BUZZER_PIN);
    delay(attesa);          // Pausa tra i bip
  } 
  // Se siamo molto vicini (meno di 5cm), suono continuo
  else if (distanza > 0 && distanza <= 5) {
    tone(BUZZER_PIN, 1500);
  }
  else {
    noTone(BUZZER_PIN);
    delay(100);
  }
}
