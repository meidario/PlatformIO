#include <Arduino.h>

/*
Traffic Light
Projekt 5 - Eine Verkehrsampel
*/
// nur bei Sloeber IDE
#include "Arduino.h"
// Definiert die Pins, mit denen die Tasten und LEDs verbunden sind:
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500 // Lässt die gelbe LED 0,5 s blinken
boolean trafficWest = true; // West = true, Ost = false
int flowTime = 4000; // Zeitraum, in dem der Verkehr fliesst
int changeDelay = 2000; // Zeitraum zwischen Farbwechseln
void setup() {
// Richtet die digitalen E/A-Pins ein
pinMode(westButton, INPUT);
pinMode(eastButton, INPUT);
pinMode(westRed, OUTPUT);
pinMode(westYellow, OUTPUT);
pinMode(westGreen, OUTPUT);
pinMode(eastRed, OUTPUT);
pinMode(eastYellow, OUTPUT);
pinMode(eastGreen, OUTPUT);
// Legt den Anfangszustand der LEDs fest, im Westen zuerst grün
digitalWrite(westRed, LOW);
digitalWrite(westYellow, LOW);
digitalWrite(westGreen, HIGH);
digitalWrite(eastRed, HIGH);
digitalWrite(eastYellow, LOW);
digitalWrite(eastGreen, LOW);
}
void loop() {
}