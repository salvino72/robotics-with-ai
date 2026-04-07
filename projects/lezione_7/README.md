# Lezione 7: Robotica Mobile Avanzata (Fase 2) 🤖

Bentrovati alla settima lezione! Oggi entreremo nel vivo della "mente" del nostro robot. Dopo aver montato la struttura base nella lezione precedente, oggi completeremo l'assemblaggio e attiveremo le funzioni di navigazione autonoma: **Evitamento Ostacoli** e **Follower di Linea**.

---

## 🎯 Obiettivi della Lezione

1.  **Chiusura Hardware**: Completare il montaggio dei sensori (Ultrasuoni e Line Tracking).
2.  **Cablaggio Finale**: Collegare i sensori alla scheda di espansione.
3.  **Algoritmi di Navigazione**: Capire come il robot "vede" ed "evita" o "segue".
4.  **Integrazione Software**: Caricare ed ottimizzare il codice per la Smart Car.

---

## 🚀 Progetto Speciale: Fase 2

### 1. Completamento Montaggio

Assicuratevi che i seguenti componenti siano installati correttamente:
*   **Sensore ad Ultrasuoni (HC-SR04)**: Montato sul servomotore frontale. Permette al robot di misurare la distanza dagli oggetti.
*   **Modulo Line Tracking**: Montato sotto lo chassis anteriore. Composto da 3 sensori a infrarossi per rilevare la linea nera sul pavimento.

> [!TIP]
> Controllate bene i cavi! Un errore comune è invertire VCC e GND, il che potrebbe danneggiare i sensori. Seguite lo schema colori del manuale.

---

### 2. Navigazione Intelligente (Software)

Utilizzeremo due modalità principali. Potete testarle separatamente caricando i rispettivi sketch.

#### A. Evitamento Ostacoli (Obstacle Avoidance) 🚧
Il robot si muove in avanti finché non rileva un ostacolo. A quel punto:
1. Si ferma.
2. Muove il sensore a destra e sinistra per misurare le distanze.
3. Sceglie la direzione più libera e riprende la marcia.

#### B. Segui-linea (Line Tracking) 🛣️
Il robot utilizza i sensori IR per rimanere sopra una linea nera (solitamente nastro isolante su fondo chiaro). 
*   Se il sensore centrale rileva la linea -> Vai dritto.
*   Se il sensore sinistro rileva la linea -> Gira a sinistra.
*   Se il sensore destro rileva la linea -> Gira a destra.

---

## 💻 Codice di Esempio

All'interno di questa cartella troverete i seguenti progetti:

*   **[01_Obstacle_Avoidance](./01_Obstacle_Avoidance/01_Obstacle_Avoidance.ino)**: Codice per l'uso combinato di ultrasuoni e servo.
*   **[02_Line_Tracking](./02_Line_Tracking/02_Line_Tracking.ino)**: Codice per il modulo IR a 3 canali.

---

## 🧠 Sviluppo Assistito da IA (LLM)

Oggi useremo l'IA per **ottimizzare** i parametri di marcia. Ecco alcuni suggerimenti per i vostri prompt:

*   *"Ho un robot Elegoo V4.0. Scrivi una funzione in C++ che faccia fermare il robot se la distanza misurata dall'HC-SR04 è inferiore a 20cm, faccia una retromarcia di mezzo secondo e poi giri a destra."*
*   *"Analizza questo codice di Line Tracking e suggeriscimi come aumentare la velocità nelle rette senza perdere la linea nelle curve strette."*
*   *"Spiegami come funziona la logica 'if' quando leggo i tre sensori del modulo di tracciamento linea."*

---

## 📦 Materiale di Supporto
*   [Manuale Completo Elegoo V4.0](../../docs/README.md) (Sezione Sensori)
*   Video Tutorial: Navigazione Autonoma

---

## 🗺️ Navigazione
*   [Precedente: Lezione 6 (Fase 1)](../lezione_6/README.md)
*   [Prossima: Lezione 8 (Robotica Sociale)](../lezione_8/README.md)
*   [Pagina Progetto Speciale](../special_project/README.md)
