// Projekt 3: PBM-Beispiel
#include <Arduino.h>
// Projekt 4 - Beispiel für digitale Eingänge
#define LED 12 
#define BUTTON 7
void setup()
{
 pinMode(LED, OUTPUT); // Ausgang für die LED 
 pinMode(BUTTON, INPUT); // Eingang für die Taste
}
void loop()
{
 if ( digitalRead(BUTTON) == HIGH )
 {
 digitalWrite(LED, HIGH); // Schaltet die LED ein
 delay(500); // Wartet 0,5 s
 digitalWrite(LED, LOW); // Schaltet die LED aus
 }
}