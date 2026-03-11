int ledPin = 10; // Dichiariamo che il LED è collegato al pin digitale 10

void setup() {
  // Il setup viene eseguito una sola volta all'accensione 
  pinMode(ledPin, OUTPUT); // Configuriamo il pin 10 per erogare corrente (Uscita) 
}

void loop() {
  // Il loop si ripete all'infinito 
  digitalWrite(ledPin, HIGH); // Accende il LED (eroga 5V)
  delay(1000);                // Mette in pausa la scheda per 1000 millisecondi (1 secondo) 
  
  digitalWrite(ledPin, LOW);  // Spegne il LED (porta la tensione a 0V) 
  delay(1000);                // Aspetta un altro secondo prima di ricominciare 
}
