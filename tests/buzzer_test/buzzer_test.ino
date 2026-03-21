const int buzzerPin = 8;

void setup() {
}

void loop() {
  tone(buzzerPin, 1000);  // 1000 Hz tonis
  delay(500);             // skan 0.5 s

  noTone(buzzerPin);      // apstādina skaņu
  delay(500);             // pauze 0.5 s
}