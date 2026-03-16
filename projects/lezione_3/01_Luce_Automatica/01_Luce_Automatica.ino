/*
 * Lezione 3 - Esercizio 1: Luce Automatica
 * ---------------------------------------
 * Obiettivo: Accendere un LED quando la luce ambientale cala.
 * Questo sketch introduce l'uso di analogRead() e la logica di soglia.
 */

// Definizione dei PIN
const int LDR_PIN = A0;   // Pin dove è collegata la fotoresistenza
const int LED_PIN = 10;   // Pin dove è collegato il LED

// Variabili di configurazione
int sogliaLuce = 400;     // Valore sotto il quale il LED si accende (da calibrare)

void setup() {
  // Inizializziamo il PIN del LED come output
  pinMode(LED_PIN, OUTPUT);
  
  // Inizializziamo la comunicazione seriale per il debug
  Serial.begin(9600);
  Serial.println("--- Sistema Luce Automatica Avviato ---");
}

void loop() {
  // Leggiamo il valore analogico dal sensore LDR (0 - 1023)
  int valoreLuce = analogRead(LDR_PIN);
  
  // Stampiamo il valore sul monitor seriale per vederlo in tempo reale
  Serial.print("Luminosita' rilevata: ");
  Serial.println(valoreLuce);

  // Logica di controllo:
  // Se il valore è basso (c'è poca luce), accendi il LED
  if (valoreLuce < sogliaLuce) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Stato: BUIO -> LED ACCESO");
  } 
  // Altrimenti, se c'è abbastanza luce, spegnilo
  else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Stato: LUCE -> LED SPENTO");
  }

  // Piccola pausa per non intasare il Monitor Seriale
  delay(500);
}
