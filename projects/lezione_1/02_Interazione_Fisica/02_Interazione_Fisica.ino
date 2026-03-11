int ledPin = 5;      // Il LED è collegato al pin 5
int buttonPin = 2;   // Il pulsante è collegato al pin 2
int statoBottone;    // Variabile per memorizzare lo stato letto

void setup() {
  pinMode(ledPin, OUTPUT);   // Il LED riceve energia (Uscita)
  pinMode(buttonPin, INPUT); // Il pulsante invia energia alla scheda (Ingresso)
}

void loop() {
  // 1. INPUT: Leggiamo la corrente sul pin del pulsante
  statoBottone = digitalRead(buttonPin); // Restituirà HIGH se premuto, LOW se rilasciato

  // 2. ELABORAZIONE: Prendiamo una decisione
  if (statoBottone == HIGH) { // Se il bottone è premuto 
    digitalWrite(ledPin, HIGH); // Chiudiamo il circuito accendendo il LED 
  } else {                      // Altrimenti (se non è premuto)
    digitalWrite(ledPin, LOW);  // Togliamo l'energia spegnendo il LED 
  }
}
