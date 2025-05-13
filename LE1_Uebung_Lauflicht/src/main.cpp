#include "Arduino.h"

int d = 100;
void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT); // der Steuerpin für LED 1 wird
// als Ausgang festgelegt
pinMode(3, OUTPUT); // Dito für LED 2 bis LED 5
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for ( int a = 2; a < 7 ; a++ )
{
digitalWrite(a, HIGH);
delay(d);
digitalWrite(a, LOW);
delay(d);
}

// Die Schleife loop() kehrt an den Anfang zurück und
// wird wiederholt ausgeführt
}
