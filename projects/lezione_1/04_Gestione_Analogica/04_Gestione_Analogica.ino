int led = 5;      // Usiamo il pin 5 che supporta il PWM (indicato con ~ sulla scheda)
int pot = A0;     // Il potenziometro va collegato a un ingresso Analogico
int valoreLetto;  // Memorizza il valore del potenziometro
int luminosita;   // Memorizza il valore finale da inviare al LED

void setup() {
  // I pin analogici (A0) sono già impostati come input di default
  pinMode(led, OUTPUT);
}

void loop() {
  // Leggiamo la posizione della manopola. 
  // Restituisce un numero molto grande, da 0 a 1023
  valoreLetto = analogRead(pot); 

  // Il LED tramite PWM accetta però solo valori da 0 a 255. 
  // Usiamo "map" per creare una proporzione matematica e scalare i valori
  luminosita = map(valoreLetto, 0, 1023, 0, 255);

  // Inviamo il segnale di energia "scalato" al LED
  analogWrite(led, luminosita); 
}
