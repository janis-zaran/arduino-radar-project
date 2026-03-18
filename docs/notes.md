# UNO Q technical notes

## Serial monitoring on Arduino UNO Q

On Arduino UNO Q, serial monitoring behaves differently than on a classic Arduino Uno.

### Important distinction

- `Serial` -> UART on pins D0/D1
- `Monitor` -> USB monitoring to the computer

### Practical conclusion

For USB monitoring on Arduino UNO Q, use:

```cpp
#include <Arduino_RouterBridge.h>

void setup() {
  Monitor.begin();
}

void loop() {
  Monitor.println("hello");
  delay(1000);
}

### App Lab note

When using Arduino_RouterBridge.h in Arduino App Lab, the app may also require the MsgPack sketch library to be installed for that specific app.

### Testing notes

Servo test worked in Arduino IDE

Ultrasonic sensor test worked in Arduino App Lab with Monitor

App Lab serial monitor appeared limited to 9600 baud in this setup
---

# UNO Q tehniskās piezīmes

## Seriālā monitorēšana uz Arduino UNO Q

Uz Arduino UNO Q seriālā monitorēšana darbojas citādi nekā uz klasiskā Arduino Uno.

### Svarīgā atšķirība

- `Serial` -> UART uz piniem D0/D1
- `Monitor` -> USB monitorēšana uz datoru

### Praktiskais secinājums

Ja vēlies redzēt tekstu datorā caur USB uz Arduino UNO Q, lieto:

```cpp
#include <Arduino_RouterBridge.h>

void setup() {
  Monitor.begin();
}

void loop() {
  Monitor.println("hello");
  delay(1000);
}
### Piezīme par App Lab

Ja Arduino App Lab vidē izmanto Arduino_RouterBridge.h, konkrētajai lietotnei var būt nepieciešams papildus uzinstalēt MsgPack sketch bibliotēku.

### Testēšanas piezīmes

Servo tests darbojās Arduino IDE vidē

Ultraskaņas sensora tests darbojās Arduino App Lab vidē ar Monitor

Šajā konfigurācijā App Lab serial monitor izskatījās ierobežots līdz 9600 baud