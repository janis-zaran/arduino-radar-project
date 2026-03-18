#include <Arduino_RouterBridge.h>

const int trigPin = 10;   // Trig pins sūta ultraskaņas impulsu
const int echoPin = 11;   // Echo pins saņem atstaroto impulsu

long duration;            // impulsa ilgums mikrosekundēs
float distanceCm;         // attālums centimetros

void setup() {
  pinMode(trigPin, OUTPUT);   // Trig būs izeja
  pinMode(echoPin, INPUT);    // Echo būs ieeja

  Monitor.begin();            // UNO Q monitorēšanai uz datora
  delay(2000);                // maza pauze, lai monitors paspēj pieslēgties
  Monitor.println("Ultrasonic test started");
}

void loop() {
  digitalWrite(trigPin, LOW);      // sākumā nolaiž Trig uz LOW
  delayMicroseconds(2);            // īsa pauze stabilitātei

  digitalWrite(trigPin, HIGH);     // nosūta ultraskaņas impulsu
  delayMicroseconds(10);           // impulss ilgst 10 mikrosekundes
  digitalWrite(trigPin, LOW);      // beidz impulsu

  duration = pulseIn(echoPin, HIGH, 30000);  // mēra Echo HIGH ilgumu, max 30 ms
  distanceCm = duration * 0.0343 / 2;        // pārvērš laiku attālumā cm

  Monitor.print("Distance: ");
  Monitor.print(distanceCm);
  Monitor.println(" cm");

  delay(500);                      // neliela pauze starp mērījumiem
}