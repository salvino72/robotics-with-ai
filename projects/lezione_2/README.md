# Lezione 2: Fondamenti di Elettronica e Codice

📥 **Materiale Didattico:** [Scarica le Slide (PDF)](../../docs/L2-slide-Arduino_Logic.pdf)

Benvenuti alla **Lezione 2**! In questo progetto esploreremo le basi dell'interazione hardware/software con Arduino Uno, procedendo passo dopo passo. Abbiamo preparato quattro esempi progressivi, ciascuno con il proprio sketch commentato riga per riga.

Questi script offrono un percorso didattico perfetto: si parte dal controllo basilare del tempo, si passa alla logica condizionale dettata dall'interazione umana, si affronta un problema software (il blocco del processore) e infine si manipola l'intensità della corrente con segnali analogici!

---

## 1. Il classico "Blink" (Accendere e spegnere un LED)

Questo è l'esempio base per capire la struttura di uno sketch (`setup` e `loop`) e come inviare un segnale digitale (`HIGH` o `LOW`) a un componente.

**Obiettivo:** Far lampeggiare un LED per un secondo.

### 🖇️ Schema di Collegamento
*   **LED:** Collegare l'anodo (gamba lunga) al Pin Digitale **10** di Arduino (usando una resistenza da 220 Ohm in serie). Collegare il catodo (gamba corta) al **GND**.

📂 **Codice Sorgente:** [01_Blink.ino](./01_Blink/01_Blink.ino)

---

## 2. Interazione Fisica (Logica Condizionale con un Pulsante)

Qui introduciamo l'ascolto dell'ambiente fisico. Arduino legge lo stato di un pulsante e, in base a questo, prende una decisione utilizzando il costrutto logico `if / else`.

**Obiettivo:** Accendere il LED solo quando il pulsante viene premuto.

### 🖇️ Schema di Collegamento
*   **LED:** Resistenza e Anodo al Pin **5**, Catodo al **GND**.
*   **Pulsante:** Un terminale al Pin **2**, l'altro ai **5V**. Inserire anche una resistenza di pull-down (es. 10k Ohm) tra il Pin 2 e il **GND** per stabilizzare la lettura.

📂 **Codice Sorgente:** [02_Interazione_Fisica.ino](./02_Interazione_Fisica/02_Interazione_Fisica.ino)

---

## 3. Logica Avanzata (Blink Non Bloccante con `millis()`)

Come abbiamo visto, usare `delay()` blocca il processore, impedendogli di leggere altri sensori durante l'attesa. Per fare più cose contemporaneamente, usiamo la funzione `millis()`, che funziona come un cronometro.

**Obiettivo:** Far lampeggiare un LED senza impedire ad Arduino di eseguire altre operazioni nel frattempo.

### 🖇️ Schema di Collegamento
*   **LED:** Resistenza e Anodo al Pin **5**, Catodo al **GND**.

📂 **Codice Sorgente:** [03_Blink_Millis.ino](./03_Blink_Millis/03_Blink_Millis.ino)

---

## 4. Gestione Analogica dell'Energia (Potenziometro e PWM)

Se non vogliamo solo accendere/spegnere un LED, ma regolarne la luminosità in modo continuo (come un dimmer), dobbiamo usare il segnale PWM e la funzione matematica `map()`.

**Obiettivo:** Regolare l'intensità luminosa di un LED ruotando la manopola di un potenziometro.

### 🖇️ Schema di Collegamento
*   **LED (PWM):** Resistenza e Anodo al Pin **5** (contrassegnato con `~` per il supporto PWM), Catodo al **GND**.
*   **Potenziometro:** 
    *   Pin esterno sinistro: **5V**
    *   Pin esterno destro: **GND**
    *   Pin centrale (cursore): Pin Analogico **A0**

📂 **Codice Sorgente:** [04_Gestione_Analogica.ino](./04_Gestione_Analogica/04_Gestione_Analogica.ino)
