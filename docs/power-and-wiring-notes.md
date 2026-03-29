# Power and Wiring Notes / Barošanas un saslēguma piezīmes

## External Power for Servo on Arduino UNO Q / Ārējā barošana servo motoram uz Arduino UNO Q

When using a servo motor with Arduino UNO Q, it is safer to power the servo from an external 5V power supply instead of the board's 5V pin.

Ja izmanto servo motoru kopā ar Arduino UNO Q, drošāk ir barot servo no ārēja 5V barošanas avota, nevis no plates 5V pina.

### Why this is important / Kāpēc tas ir svarīgi

Servo motors can draw sudden current peaks when they start moving or when they are under load.  
This can cause unstable behavior if the servo is powered directly from the Arduino board.

Servo motori kustības sākumā vai zem slodzes var paņemt īslaicīgus strāvas pīķus.  
Tas var radīt nestabilu darbību, ja servo tiek barots tieši no Arduino plates.

Possible symptoms / Iespējamie simptomi:

- servo twitches or stops moving / servo raustās vai apstājas
- the board behaves unpredictably / plate sāk uzvesties nestabili
- sensors stop working correctly / sensori sāk strādāt nepareizi
- uploads or tests become unstable / upload vai testi kļūst nestabili

### Recommended approach / Ieteicamā pieeja

- Power the **servo** from an **external 5V supply**
- Keep the **servo signal wire** connected to the Arduino pin
- Connect the **external power supply GND** to **Arduino GND**

- barot **servo** no **ārēja 5V avota**
- atstāt **servo signāla vadu** pieslēgtu Arduino pinam
- savienot **ārējā barošanas avota GND** ar **Arduino GND**

### Important note about GND / Svarīga piezīme par GND

The external power supply GND must be connected to Arduino GND.

This is necessary because the servo signal needs a common voltage reference.  
Without a shared GND, the servo may not correctly understand the signal coming from the Arduino.

Ārējā barošanas avota GND obligāti jāsavieno ar Arduino GND.

Tas ir nepieciešams tāpēc, ka servo signālam vajag kopīgu atskaites punktu.  
Ja GND nav kopīgs, servo var nesaprast Arduino sūtīto signālu pareizi.

---

## Breadboard Note / Piezīme par breadboard

Breadboards are convenient for prototyping, but they are not ideal for higher current loads such as servo motors.

Breadboard ir ļoti ērts prototipēšanai, bet tas nav ideāls lielākām strāvām, piemēram, servo motoru barošanai.

### Practical recommendation / Praktiska rekomendācija

Use the breadboard for / Breadboard ir labi izmantot:

- signal wiring / signālu vadiem
- sensors / sensoriem
- OLED display / OLED displejam
- buzzer / buzzerim
- low-power peripherals / mazjaudas perifērijām

Avoid using the breadboard power rails as the main power path for current-hungry devices like servos.

Nevajadzētu izmantot breadboard barošanas sliedes kā galveno barošanas ceļu strāvu prasīgām ierīcēm, piemēram, servo motoram.

### Better approach / Labāka pieeja

Power the servo directly from the external 5V supply using separate wires.

Servo labāk barot tieši no ārējā 5V avota ar atsevišķiem vadiem.

---

## Safe Wiring Example / Drošs saslēguma piemērs

### Servo

- Servo VCC -> External 5V / ārējais 5V
- Servo GND -> External GND / ārējais GND
- Servo signal -> Arduino UNO Q D9

### Shared Ground / Kopīgais GND

- External GND -> Arduino UNO Q GND
- Ārējais GND -> Arduino UNO Q GND

### Ultrasonic Sensor / Ultraskaņas sensors

- VCC -> Arduino UNO Q 5V
- GND -> Arduino UNO Q GND
- Trig -> Arduino UNO Q D10
- Echo -> Arduino UNO Q D11

---

## ASCII Wiring Diagram / ASCII saslēguma shēma

```text
                 +----------------------+
                 | External 5V supply   |
                 | Ārējais 5V avots     |
                 |                      |
                 | +5V ------------+    |
                 |                 |    |
                 | GND ---------+  |    |
                 +--------------|--|----+
                                |  |
                                |  +---------------------> Servo VCC
                                |
                                +-------------------------> Servo GND
                                |
                                +-------------------------> Arduino UNO Q GND

+------------------------------------------------------+
| Arduino UNO Q                                        |
|                                                      |
| GND -------------------------------------------------+
|                                                      |
| D9  -----------------------------------------------> Servo signal
|                                                      |
| 5V  -----------------------------------------------> Ultrasonic VCC
| GND -----------------------------------------------> Ultrasonic GND
| D10 -----------------------------------------------> Ultrasonic Trig
| D11 -----------------------------------------------> Ultrasonic Echo
|                                                      |
+------------------------------------------------------+