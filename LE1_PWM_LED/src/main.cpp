// Projekt 3: PBM-Beispiel
#include <Arduino.h>
int d = 5;
void setup()
{
pinMode(3, OUTPUT); // Der LED-Steuerpin ist Nr. 3, er ist PBM-fähig
}



void loop()
{
for ( int a = 0 ; a < 256 ; a++ )
{
analogWrite(3, a);
delay(d);
}
for ( int a = 255 ; a >= 0 ; a-- )
{
analogWrite(3, a);
delay(d);
}
delay(200);
}