#include <Servo.h>      // pieslēdz Servo bibliotēku, kas ļauj kontrolēt servo motoru

Servo myServo;          // izveido servo objektu ar nosaukumu "myServo"

void setup() {          // setup() funkcija izpildās vienu reizi, kad Arduino ieslēdzas
  myServo.attach(9);    // pieslēdz servo objektu pie Arduino 9. pina (signāla vads)
}

void loop() {           // loop() funkcija atkārtojas bezgalīgi

  // Testa kustība: 0° → 90° → 180° → atkārto
  // Piezīme: pēc 180° servo ies pa taisno atpakaļ uz 0°,
  // neapstājoties pie 90°. Gala radar kodā taisīsim gludu skenēšanu.

  myServo.write(0);     // pagriež servo uz 0 grādiem
  delay(1000);          // pagaida 1 sekundi (1000 milisekundes)

  myServo.write(90);    // pagriež servo uz 90 grādiem
  delay(1000);          // pagaida 1 sekundi (1000 milisekundes)

  myServo.write(180);   // pagriež servo uz 180 grādiem
  delay(1000);          // pagaida 1 sekundi (1000 milisekundes)
}