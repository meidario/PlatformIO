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
DEBUG_PRINTLN("Hello World");
}
// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}