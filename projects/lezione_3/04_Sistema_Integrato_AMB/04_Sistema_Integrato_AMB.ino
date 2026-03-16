/*
 * Lezione 3 - Esercizio 4: Sistema Integrato Monitoraggio Ambiente
 * -------------------------------------------------------------
 * Obiettivo: Integrare piu' sensori per valutare la salute di un ambiente (es. Serra).
 * Livello: Avanzato (Logica Booleana e Multi-sensore).
 */

#include "DHT.h"

// PIN Sensori
const int LDR_PIN = A0;
const int DHT_PIN = 2;

// PIN Indicatori (LED)
const int LED_OK = 4;      // LED Verde
const int LED_FAIL = 5;    // LED Rosso

// Configurazione DHT
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);

// Soglie ideali (Esempio per una pianta da interno)
const int SOGLIA_LUCE_OK = 300;     // Sopra questo valore c'è luce sufficiente
const float SOGLIA_TEMP_MAX = 28.0; // Sotto questo valore la temperatura è ok

void setup() {
  Serial.begin(9600);
  pinMode(LED_OK, OUTPUT);
  pinMode(LED_FAIL, OUTPUT);
  
  dht.begin();
  
  Serial.println("--- Sistema di Monitoraggio Serra avviato ---");
}

void loop() {
  // 1. Lettura Sensori
  int luce = analogRead(LDR_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Controllo validita' dati DHT
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Errore lettura DHT!");
    delay(2000);
    return;
  }

  // 2. Analisi della situazione (Logica Booleana)
  // Vogliamo che ci sia luce E la temperatura non sia troppo alta
  bool luceSufficiente = (luce > SOGLIA_LUCE_OK);
  bool temperaturaOK = (temp < SOGLIA_TEMP_MAX);

  // 3. Feedback Visivo e Seriale
  Serial.print("Dati: L:"); Serial.print(luce);
  Serial.print(" | T:"); Serial.print(temp);
  Serial.print(" | U:"); Serial.println(hum);

  if (luceSufficiente && temperaturaOK) {
    // Tutto perfetto!
    digitalWrite(LED_OK, HIGH);
    digitalWrite(LED_FAIL, LOW);
    Serial.println(">>> STATO: CONDIZIONI OTTIMALI");
  } 
  else {
    // C'è qualcosa che non va
    digitalWrite(LED_OK, LOW);
    digitalWrite(LED_FAIL, HIGH);
    
    // Specifichiamo il problema sulla Serial
    if (!luceSufficiente) Serial.println(">>> ALLERTA: Poca luce!");
    if (!temperaturaOK)   Serial.println(">>> ALLERTA: Troppo caldo!");
  }

  // Pausa tra i cicli
  delay(3000);
}
