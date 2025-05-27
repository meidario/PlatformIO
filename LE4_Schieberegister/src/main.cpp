#include "Arduino.h"
// Projekt 16: Eine Binärzahlenanzeige aus LEDs bauen
#define DATA 6 // Digitalpin 6 an Pin 14 des 74HC595
#define LATCH 8 // Digitalpin 8 an Pin 12 des 74HC595
#define CLOCK 10 // Digitalpin 10 an Pin 11 des 74HC595
void setup()
{
 pinMode(LATCH, OUTPUT);
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, OUTPUT);
}
void loop()
{
 int i;
 for ( i = 0; i < 256; i++ )
 {
 digitalWrite(LATCH, LOW);
 shiftOut(DATA, CLOCK, MSBFIRST, i);
 digitalWrite(LATCH, HIGH);
 delay(200);
 }
}