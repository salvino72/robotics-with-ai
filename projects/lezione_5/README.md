# Lezione 5: Robotica Mobile e Attuatori ⚙️

📥 **Materiale Didattico:** [Scarica le Slide - Robotic Motion Blueprint (PDF)](../../docs/L5_slide_Robotic_Motion_Blueprint.pdf)

Benvenuti alla **Lezione 5** del corso di Robotica con Intelligenza Artificiale! In questa lezione passeremo dalla teoria alla pratica del movimento, esplorando come un robot può interagire fisicamente con l'ambiente circostante.

---

## 📖 Gli Argomenti della Lezione

*   **Movimento e Attuatori**
    Scopriremo i "muscoli" del robot: i motori a corrente continua (DC) per la rotazione continua (ruote) e i servomotori per il posizionamento preciso (bracci robotici, sterzo).
*   **Design di Robot Mobili**
    Approfondiremo l'uso di chassis, l'importanza di una corretta alimentazione tramite batterie e l'integrazione di driver come l'**L298N** per gestire correnti elevate.
*   **Cinematica Base**
    Impareremo a programmare percorsi, gestire curve attraverso la trazione differenziale e regolare la velocità dei motori tramite segnali PWM.

---

## 🧠 L'Anatomia del Movimento: Il Cervello e il Muscolo

Una delle chiavi per capire la robotica mobile è la distinzione tra **Logica** e **Potenza**:

*   **Il Cervello (Arduino):** Ragiona elaborando logica digitale a bassa potenza. Invia i "comandi" ma non ha la forza per muovere i motori direttamente.
*   **Il Muscolo (Driver L298N):** È l'attuatore elettromagnetico che traduce i segnali logici in spostamento spaziale. Gestisce l'energia "grezza" delle batterie e la convoglia ai motori.

> **💡 Concetto Chiave:** Collegare un motore DC direttamente ai pin di Arduino potrebbe bruciare la scheda. L'Arduino fornisce la logica, il driver fornisce la potenza!

---

## 🛠️ Progetti Pratici

In questa cartella troverete quattro progetti guidati per mettere in pratica i concetti studiati:

1.  **[01_Controllo_Motore_DC](./01_Controllo_Motore_DC/01_Controllo_Motore_DC.ino)**: Impara a pilotare un motore DC avanti e indietro usando un driver Ponte H.
2.  **[02_Controllo_Servo](./02_Controllo_Servo/02_Controllo_Servo.ino)**: Gestisci un servomotore SG90 per posizionamenti angolari precisi (0-180°).
3.  **[03_Robot_Differenziale](./03_Robot_Differenziale/03_Robot_Differenziale.ino)**: Costruisci la logica di movimento per un robot a due ruote (avanti, svolte sul posto).
4.  **[04_Controllo_Velocita_PWM](./04_Controllo_Velocita_PWM/04_Controllo_Velocita_PWM.ino)**: Sperimenta con il PWM per creare curve fluide e accelerazioni graduali.

---

## 💻 Non hai l'hardware? Usa un Simulatore!

Non preoccuparti se non hai a disposizione motori, driver L298N o un telaio robotico. Puoi svolgere **tutti e quattro i progetti** utilizzando simulatori online gratuiti che replicano fedelmente il comportamento di Arduino e dei suoi componenti.

### ✅ Simulatore Consigliato: Tinkercad Circuits

**[Tinkercad Circuits](https://www.tinkercad.com/circuits)** (di Autodesk) è la soluzione migliore per i principianti:

*   **Gratuito** — Basta creare un account Autodesk (gratuito).
*   **Nessuna installazione** — Funziona interamente nel browser web.
*   **Componenti disponibili** — Include Arduino Uno, motori DC, servomotori, driver Ponte H (L298N), batterie, LED, resistenze e molto altro.
*   **Simulazione del codice** — Puoi scrivere o incollare il codice `.ino`, avviare la simulazione e osservare il comportamento del circuito in tempo reale.
*   **Monitor Seriale integrato** — Visualizza i messaggi di debug come su un Arduino reale.

### 🚀 Come usare Tinkercad per i progetti di questa lezione

1.  Vai su [tinkercad.com/circuits](https://www.tinkercad.com/circuits) e accedi (o crea un account gratuito).
2.  Clicca su **"Crea nuovo Circuito"**.
3.  Dalla barra laterale, trascina i componenti necessari (Arduino Uno, motore DC, servomotore, ponte H, ecc.).
4.  Collega i fili seguendo gli schemi descritti nel codice di ciascun progetto (pin IN1, IN2, ENA, ecc.).
5.  Clicca sulla scheda **"Codice"** in alto, seleziona **"Testo"** e incolla il codice `.ino` del progetto.
6.  Premi il pulsante **"Avvia Simulazione"** ▶️ e osserva il motore girare!

### 🔧 Alternative di Simulazione

| Simulatore | Tipo | Punti di Forza | Link |
| :--- | :--- | :--- | :--- |
| **Tinkercad Circuits** | Online, gratuito | Interfaccia drag-and-drop, ideale per principianti | [tinkercad.com/circuits](https://www.tinkercad.com/circuits) |
| **Wokwi** | Online, gratuito | Supporta molte board (ESP32, Arduino Mega), veloce | [wokwi.com](https://wokwi.com/) |
| **SimulIDE** | Desktop, open source | Simulazione circuitale avanzata, elettronica dettagliata | [simulide.com](https://www.simulide.com/) |
| **Proteus (ISIS)** | Desktop, a pagamento | Professionale, simula anche PCB e microcontrollori complessi | [labcenter.com](https://www.labcenter.com/) |

> **💡 Suggerimento:** Per i Progetti 01 e 02 (singolo motore/servo), **Tinkercad** è perfetto. Per i Progetti 03 e 04 (robot a 2 ruote), **Wokwi** offre un'ottima esperienza con modelli di robot già pronti.

---

## 🧐 FAQ — Domande Frequenti

### Cos'è un driver Ponte H (L298N) e perché serve?
I motori DC assorbono molta più corrente di quella che i pin di Arduino possono fornire (massimo ~40 mA per pin). Il **Ponte H** è un circuito integrato che funge da "interruttore di potenza": riceve i **segnali logici** da Arduino (HIGH/LOW) e li usa per controllare il flusso di corrente dal **pacco batterie** ai motori, permettendo rotazione in entrambe le direzioni.

### Qual è la differenza tra un motore DC e un servomotore?
| Caratteristica | Motore DC | Servomotore |
| :--- | :--- | :--- |
| **Tipo di rotazione** | Continua (360°) | Limitata (0-180°) |
| **Controllo** | Velocità (PWM) | Posizione angolare (gradi) |
| **Uso tipico** | Ruote, eliche | Sterzo, bracci robotici, pinze |
| **Libreria Arduino** | Nessuna (controllo diretto pin) | `Servo.h` |
| **Driver necessario?** | Sì (es. L298N) | No (collegamento diretto) |

### Cosa significa PWM e come controlla la velocità?
**PWM** (Pulse Width Modulation) è una tecnica in cui Arduino accende e spegne un pin digitale molto velocemente. Variando il rapporto tra tempo "acceso" e tempo "spento" (duty cycle), si controlla la potenza media erogata al motore. Su Arduino si usa `analogWrite(pin, valore)` con valori da **0** (fermo) a **255** (massima velocità).

### Come funziona la trazione differenziale?
Un robot a due ruote indipendenti sterza giocando sulla **differenza di velocità** tra la ruota sinistra e la destra:
*   **Dritto:** entrambe le ruote avanti alla stessa velocità.
*   **Curva a destra:** ruota sinistra più veloce della destra (o destra ferma).
*   **Curva a sinistra:** ruota destra più veloce della sinistra (o sinistra ferma).
*   **Rotazione sul posto:** una ruota avanti e l'altra indietro.

### La Regola d'Oro del Cablaggio 🔴⚫
Per evitare che il tuo robot giri su se stesso quando gli ordini di andare avanti, mantieni una **rigida coerenza dei colori** durante la saldatura e il collegamento dei cavi (es. Rosso per il positivo e Nero per il negativo). Se inverti i cavi di un solo motore, le ruote gireranno in direzioni opposte!

### Lo Snodo Energetico: Gestione dell'Alimentazione
In un robot mobile, l'energia deve essere "domata":
1.  **Potenza Grezza:** Un pacco batterie (es. 6xAA per ~9V o Li-Po) si collega direttamente al morsetto VCC del driver L298N.
2.  **Logica Sicura:** Il driver L298N ha un regolatore interno che fornisce un'uscita stabilizzata a **5V**. Usa questa uscita per alimentare la scheda Arduino. Questo garantisce che i "muscoli" non disturbino il "cervello".

### Il Segreto della Fluidità: PWM
Il PWM (Pulse Width Modulation) non è magia, è velocità! Arduino "inganna" i motori accendendo e spegnendo l'energia migliaia di volte al secondo:
*   **Duty Cycle 25% (`analogWrite(64)`):** Il motore riceve energia per poco tempo, gira piano.
*   **Duty Cycle 75% (`analogWrite(191)`):** Il motore riceve energia per la maggior parte del tempo, gira forte.

### Posso usare un servomotore a rotazione continua al posto di un motore DC?
Sì, esistono servomotori a **rotazione continua** (es. FS90R) che si controllano come un servo normale ma dove `write(90)` = fermo, `write(0)` = massima velocità in un verso, `write(180)` = massima velocità nell'altro. Sono un'alternativa valida per robot semplici che non necessitano di alte velocità.

### Cos'è il PID e quando mi serve?
**PID** (Proporzionale-Integrale-Derivativo) è un algoritmo di controllo avanzato che corregge automaticamente la traiettoria del robot. Si usa nei **robot autonomi** (es. line-follower) dove i sensori rilevano lo scostamento dalla linea e il PID calcola la correzione da applicare ai motori. Non è necessario per i progetti base di questa lezione, ma è il passo successivo per chi vuole approfondire.

---

## 📚 Risorse e Link Utili

### 📖 Documentazione e Guide

| Risorsa | Descrizione | Link |
| :--- | :--- | :--- |
| **Arduino Reference — Servo** | Documentazione ufficiale della libreria `Servo.h` | [arduino.cc/reference/en/libraries/servo/](https://www.arduino.cc/reference/en/libraries/servo/) |
| **Arduino Reference — analogWrite** | Guida al controllo PWM con Arduino | [arduino.cc/reference/en/language/functions/analog-io/analogwrite/](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) |
| **L298N Datasheet** | Scheda tecnica del driver Ponte H | [sparkfun.com/datasheets/Robotics/L298_H_Bridge.pdf](https://www.sparkfun.com/datasheets/Robotics/L298_H_Bridge.pdf) |
| **Servo SG90 Datasheet** | Specifiche tecniche del micro servo | [components101.com/motors/servo-motor-basics-pinout-datasheet](https://components101.com/motors/servo-motor-basics-pinout-datasheet) |

### 🎥 Video Tutorial

| Video | Canale | Argomento | Link |
| :--- | :--- | :--- | :--- |
| Motore DC con L298N | Paul McWhorter | Controllo motore passo-passo | [youtube.com — Lesson 39](https://www.youtube.com/watch?v=fPLEncYrl4Q) |
| Servo Motor con Arduino | Paul McWhorter | Gestione servomotori SG90 | [youtube.com — Lesson 35](https://www.youtube.com/watch?v=aFHu65LiFok) |
| Robot Car con Arduino | DroneBot Workshop | Costruzione completa robot 2WD | [youtube.com — Robot Car](https://www.youtube.com/watch?v=1n_KjpMfVT0) |
| PID Line Follower | Electronoobs | Algoritmo PID su line-follower | [youtube.com — PID Robot](https://www.youtube.com/watch?v=AMBWV_HGYj4) |

### 🛒 Dove Acquistare i Componenti

| Negozio | Note | Link |
| :--- | :--- | :--- |
| **Amazon.it** | Kit Arduino con motori e driver L298N | [amazon.it](https://www.amazon.it/s?k=arduino+robot+car+kit) |
| **AZ-Delivery** | Componenti elettronici per Arduino (spedizione EU) | [az-delivery.de/it](https://www.az-delivery.de/it/) |
| **Elegoo** | Kit completi robot car con telaio e motori | [elegoo.com](https://www.elegoo.com/) |
| **Banggood** | Componenti economici, spedizione internazionale | [banggood.com](https://www.banggood.com/) |

### 🔗 Progetti e Community

| Risorsa | Descrizione | Link |
| :--- | :--- | :--- |
| **Arduino Project Hub** | Progetti condivisi dalla community Arduino | [create.arduino.cc/projecthub](https://create.arduino.cc/projecthub) |
| **Instructables — Robotics** | Guide passo-passo per robot fai-da-te | [instructables.com/circuits/robots/](https://www.instructables.com/circuits/robots/) |
| **Forum Arduino** | Community ufficiale per domande e supporto | [forum.arduino.cc](https://forum.arduino.cc/) |
| **Reddit r/arduino** | Subreddit dedicato a progetti Arduino | [reddit.com/r/arduino](https://www.reddit.com/r/arduino/) |
| **Hackster.io** | Piattaforma di progetti hardware open source | [hackster.io](https://www.hackster.io/) |

---

## 🗺️ Navigazione
*   [Torna alla Home](../../README.md)
*   [Lezione Precedente: Droni e Volo APR](../lezione_4/README.md)
*   [Prossima Lezione: Sviluppo Avanzato e AI](../lezione_6/README.md)

---

*N.B. Ricordate di collegare sempre l'alimentazione del driver motori separatamente rispetto a quella dell'Arduino per evitare riavvii indesiderati dovuti all'assorbimento di corrente!*
