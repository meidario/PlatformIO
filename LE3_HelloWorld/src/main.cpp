#include <Arduino.h>

#define DEBUG // "Schalter" zum aktivieren
#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif
// The setup function is called once at startup of the sketch
void setup()
{
    Serial.begin(9600);
    DEBUG_PRINTLN("Hello World");

    int size = 10;
    int values[size];
    for (int cnt = 0; cnt < size; cnt++)
    {
        values[cnt] = cnt;
    }
    for (int cnt = 0; cnt < size; cnt++)
    {
        DEBUG_PRINTLN(values[cnt]);
    }

char str1[5] = {'T', 'e', 's', 't', '\0'}; // \0 beendet den String
char str2[] = "Hallo"; // nach der Deklaration ist das Array 5 lang
char str3[5] = "Velo";
char str4[15] = "ok"; // platz halten für einen grösseren String

for (int cnt=0; cnt<size; cnt++) {
char buf[25];
sprintf(buf, "%d values[%d] = %d", str3,cnt, values[cnt]);
DEBUG_PRINTLN(buf);
}

// Sinus
const float pi = 3.14;
int wave[256];
float rad = 0;
for (int i = 0; i < 256; i++ ) {
rad = rad + (2.00 * pi / 256.00);
wave[i] = (sin(rad) * 128) + 128;
char buf[64];
char strbuf[8];
dtostrf(rad, 3, 3, strbuf);
sprintf(buf, "rad=%s, wave[i]=%d", strbuf, wave[i]);
DEBUG_PRINTLN(buf);
}


}

// The loop function is called in an endless loop
void loop()
{
    // Add your repeated code here
}