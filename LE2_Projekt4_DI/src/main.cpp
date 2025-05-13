#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
 pinMode(LED, INPUT); // Eingang für die Taste
}

void loop() {
  // put your main code here, to run repeatedly:
 if ( digitalRead(BUTTON) == HIGH )
 {
 digitalWrite(LED, HIGH); // Schaltet die LED ein
 delay(500); // Wartet 0,5 s
 digitalWrite(LED, LOW); // Schaltet die LED aus
 }
}