# Lezione 3: Sensori e Interazione con l'Ambiente 🌡️

📥 **Materiale Didattico:** [Scarica le Slide (PDF)](../../docs/L3-slide-Digital_Nervous_System.pdf)

Benvenuti alla **Lezione 3**! In questa sessione faremo fare un salto di qualità ai nostri progetti: il robot smetterà di essere un semplice dispositivo che esegue comandi temporizzati e inizierà a **percepire il mondo esterno**.

Esploreremo come Arduino utilizza i sensori per raccogliere dati analogici e digitali (luce, temperatura, distanza) e come processare queste informazioni per prendere decisioni autonome.

---

## 1. Luce Automatica (Il sensore LDR)

Il primo passo per interagire con l'ambiente è misurare l'intensità luminosa. Utilizzeremo una fotoresistenza (LDR) per creare un sistema che si attiva solo quando scende il buio.

**Obiettivo:** Accendere un LED automaticamente quando la luce ambientale scende sotto una certa soglia.

### 🖇️ Schema di Collegamento
*   **LDR:** Collegato a **5V** e al Pin Analogico **A0** (con una resistenza da 10k Ohm verso il **GND** - partitore di tensione).
*   **LED:** Collegato al Pin **10** (con resistenza da 220 Ohm).

📂 **Codice Sorgente:** [01_Luce_Automatica.ino](./01_Luce_Automatica/01_Luce_Automatica.ino)

---

## 2. Termostato Digitale (Sensore DHT11)

Passiamo a sensori più complessi che comunicano dati digitali. Il DHT11 ci permette di leggere sia la temperatura che l'umidità dell'aria.

**Obiettivo:** Leggere i dati ambientali, mostrarli sul Monitor Seriale e attivare un segnale di allarme se la temperatura supera i 30°C.

### 🖇️ Schema di Collegamento
*   **DHT11:** Pin VCC a **5V**, GND a **GND**, e Pin Dati al Pin Digitale **2**.
*   **LED Allarme:** Collegato al Pin **8**.

📂 **Codice Sorgente:** [02_Termostato_Seriale.ino](./02_Termostato_Seriale/02_Termostato_Seriale.ino)

---

## 3. Radar di Prossimità (Sensore ad Ultrasuoni HC-SR04)

Come fanno i robot a non sbattere contro gli ostacoli? Usano il "sonar". Il sensore HC-SR04 misura la distanza emettendo ultrasuoni.

**Obiettivo:** Creare un sensore di parcheggio che emette un suono (Buzzer) sempre più frequente man mano che ci si avvicina a un oggetto.

### 🖇️ Schema di Collegamento
*   **HC-SR04:** VCC (**5V**), GND (**GND**), Trig (Pin **9**), Echo (Pin **10**).
*   **Buzzer:** Collegato al Pin **6**.

📂 **Codice Sorgente:** [03_Radar_Distanza.ino](./03_Radar_Distanza/03_Radar_Distanza.ino)

---

## 4. Sistema Integrato: Monitoraggio Pianta Intelligente

L'ultimo livello combina più sensori per creare un sistema di monitoraggio completo. Il robot valuterà se le condizioni ambientali sono ottimali per una pianta.

**Obiettivo:** Analizzare luce e umidità contemporaneamente. Se entrambi i valori sono bassi, il sistema segnala che la pianta ha bisogno di cure.

### 🖇️ Schema di Collegamento
*   **LDR:** Pin **A0**.
*   **DHT11:** Pin **2**.
*   **LED RGB o 2 LED (Verde/Rosso):** Pin **4** (Verde) e **5** (Rosso).

📂 **Codice Sorgente:** [04_Sistema_Integrato_AMB.ino](./04_Sistema_Integrato_AMB/04_Sistema_Integrato_AMB.ino)

---

## 🧐 Approfondimenti e Sfide (FAQ)

### Come scegliere la "Soglia" giusta?
In sensori come la fotoresistenza (LDR), il valore letto dipende molto dalla luce della stanza. 
*   **Trucco:** Apri il **Monitor Seriale**, leggi il valore in una condizione di luce normale e poi copri il sensore con la mano. Scegli un valore che stia nel mezzo!

### Perché i sensori hanno bisogno di una resistenza?
Nel caso della fotoresistenza, usiamo un **Partitore di Tensione**. Arduino non può misurare la "resistenza" direttamente, può solo misurare la **tensione (Volt)**. La resistenza aggiuntiva ci permette di convertire la variazione di resistenza in una variazione di tensione che Arduino può leggere.

### Sfida per te: "Smart City" 🏙️
Prova a combinare l'Esercizio 1 (Luce) e l'Esercizio 3 (Radar). 
*   **Idea:** Crea un lampione intelligente che si accende solo se è buio **E** se qualcuno sta passando vicino (rilevato dal radar). Questo è il vero risparmio energetico!

