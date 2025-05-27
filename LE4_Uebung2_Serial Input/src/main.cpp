#include <Arduino.h>
#define DEBUG // "Schalter" zum aktivieren
#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif
//The setup function is called once at startup of the sketch
void setup()
{
Serial.begin(9600);
DEBUG_PRINTLN("Enter number exercise");
delay(100);
}
// The loop function is called in an endless loop
void loop()
{
Serial.print("\n\nPlease enter a number: ");
int number = 0; // Setzt number auf 0, um einen neuen Wert
// empfangen zu können
Serial.flush(); // Leert den seriellen Puffer, bevor wieder
// gewartet wird
while (Serial.available() == 0)
{
// Tut nichts, bis etwas im seriellen Puffer ankommt
}
String tmp = Serial.readString();
number = tmp.toInt();
// Zeigt die eingegebene Zahl und das Ergebnis der Multiplikation an
Serial.print("You entered: ");
Serial.println(number);
Serial.print(number);
Serial.print(" multiplied by two is ");
number = number * 2;
Serial.println(number);
}