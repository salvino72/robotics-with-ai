int led = 5; 
unsigned long t1; // Variabile per memorizzare l'ultimo istante del cambio di stato
unsigned long dt; // Variabile per calcolare la differenza di tempo passata
unsigned long tBlink = 750; // Vogliamo far lampeggiare il LED ogni 750 ms

void setup() {
  pinMode(led, OUTPUT); 
  t1 = millis(); // Salviamo il tempo iniziale calcolato dall'accensione
}

void loop() {
  // Calcoliamo quanto tempo è trascorso dall'ultimo "salvataggio"
  dt = millis() - t1;

  // Se la differenza di tempo supera i 750 ms...
  if (dt > tBlink) {
    // ...invertiamo lo stato del LED. Il "!" (Not) legge lo stato attuale e fa l'opposto
    digitalWrite(led, !digitalRead(led)); 
    
    // Aggiorniamo il cronometro per il prossimo ciclo
    t1 = millis(); 
  }
  
  // Fuori da questo "if", Arduino è libero di leggere altri sensori senza blocchi!
}
