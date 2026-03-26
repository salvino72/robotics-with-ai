#include <Servo.h>

/*
  Progetto 02: Controllo Servomotore SG90
  Questo sketch sposta il servomotore tra angoli specifici (0, 90, 180 gradi).
*/

// Creazione di un oggetto servo per ogni motore che vogliamo controllare
Servo myservo;

// Definizione del pin di controllo per il Servomotore
const int servoPin = 9;

void setup() {
  myservo.attach(servoPin); // Collega l'oggetto servo al pin digitiale 9
  Serial.begin(9600);
}

void loop() {
  // Sposta il servo a 0 gradi
  Serial.println("Angolo: 0 gradi");
  myservo.write(0);
  delay(1000);
  
  // Sposta il servo a 90 gradi (centrale)
  Serial.println("Angolo: 90 gradi");
  myservo.write(90);
  delay(1000);
  
  // Sposta il servo a 180 gradi
  Serial.println("Angolo: 180 gradi");
  myservo.write(180);
  delay(1000);
  
  // Scansione da 0 a 180 gradi
  Serial.println("Scansione 0 -> 180");
  for (int pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  
  // Scansione da 180 a 0 gradi
  Serial.println("Scansione 180 -> 0");
  for (int pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
}
