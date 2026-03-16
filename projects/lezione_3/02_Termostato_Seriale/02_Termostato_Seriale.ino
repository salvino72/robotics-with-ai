/*
 * Lezione 3 - Esercizio 2: Termostato Seriale
 * ------------------------------------------
 * Obiettivo: Leggere temperatura e umidità e gestire un allarme termico.
 * NOTA: Richiede la libreria "DHT sensor library" di Adafruit.
 */

#include "DHT.h"

// Definizione dei PIN e del tipo di sensore
const int DHT_PIN = 2;      // Pin dati del sensore DHT
const int ALARM_PIN = 8;    // LED di allarme
#define DHTTYPE DHT11       // Stiamo usando il modello DHT11

// Inizializzazione del sensore
DHT dht(DHT_PIN, DHTTYPE);

// Soglia di temperatura per l'allarme
float sogliaTemp = 30.0;

void setup() {
  Serial.begin(9600);
  Serial.println("--- Avvio Termostato Digitale ---");
  
  pinMode(ALARM_PIN, OUTPUT);
  
  // Avvio del sensore DHT
  dht.begin();
}

void loop() {
  // Aspettiamo almeno 2 secondi tra una lettura e l'altra (il DHT11 è lento)
  delay(2000);

  // Lettura umidità (percentuale)
  float h = dht.readHumidity();
  // Lettura temperatura (Celsius)
  float t = dht.readTemperature();

  // Controllo se le letture sono valide
  if (isnan(h) || isnan(t)) {
    Serial.println("Errore: Impossibile leggere dal sensore DHT!");
    return;
  }

  // Visualizzazione dati sul Monitor Seriale
  Serial.print("Umidita': ");
  Serial.print(h);
  Serial.print("%  |  ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  // Logica di Allarme:
  // Se la temperatura supera la soglia, il LED lampeggia
  if (t > sogliaTemp) {
    digitalWrite(ALARM_PIN, HIGH);
    Serial.println("!!! ATTENZIONE: TEMPERATURA ELEVATA !!!");
  } else {
    digitalWrite(ALARM_PIN, LOW);
  }
}
