#include "Arduino.h"
#define DEBUG // "Schalter" zum aktivieren
#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif
int computeDoubleValue(int a);
void computeDoublePointer(int *a);
void computeDoubleReference(int &a);
int computeDoubleDefault(int a=4);

void print (const char str[], int number);
void print (const char str[], float number);
//The setup function is called once at startup of the sketch
void setup()
{
 Serial.begin(9600);
 int a1 = 1, a2 = 2, a3 = 3;
 float a105 = 10.5;
 DEBUG_PRINTLN("Testing function calls");
 print("Call by int Value (exp 2): ", computeDoubleValue(a1));

 computeDoublePointer(&a2);
 print("Call by void Pointer (exp 4): ", a2);

 computeDoubleReference(a3);
 print("Call by void reference (exp 6): ", a3);

print("Call by default Value (exp 8): ", computeDoubleDefault());
}
// The loop function is called in an endless loop
void loop()
{
 //Add your repeated code here
}
int computeDoubleValue(int a) {
return 2 * a;
}
void computeDoublePointer(int *a) {
*a = 2 * *a;
}
 
void computeDoubleReference(int &a) {
a = 2 * a;
}

int computeDoubleDefault(int a=4) {
return 2 * a;
}

void print (const char str[], int number) {
char buf[100];
sprintf(buf, "%s %d", str, number);
DEBUG_PRINTLN(buf);
}
void print (const char str[], float number) {
char buf[100];
char strbuf[10];
dtostrf(number, 3, 3, strbuf);
sprintf(buf, "%s %s", str, strbuf);
DEBUG_PRINTLN(buf);
}