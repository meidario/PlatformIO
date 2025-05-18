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
int step = 0;
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

    if (digitalRead(eastButton) == HIGH and (digitalRead(trafficWest)) == HIGH){
        /* code */
        switch (step)
        {
        case 0: //West to yellow
            /* code */
            digitalWrite(westYellow, HIGH);
            delay(changeDelay);
            step = 1;
            break;

        case 1: //West to red
            /* code */
            digitalWrite(westYellow, LOW);
            digitalWrite(westRed, HIGH);
            delay(changeDelay);
            step = 2;
            break;
        case 2: //Wait for traffic
            /* code */
            delay(flowTime);
            step = 3;
            break;
        case 3: //blink yellow east
            /* code */
            digitalWrite(eastYellow, HIGH);
            delay(yellowBlinkTime);
            digitalWrite(eastYellow, LOW);
            delay(yellowBlinkTime);
            delay(changeDelay);
            step = 4;
            break;
        case 4: //East to green
            /* code */
            digitalWrite(eastRed, LOW);
            digitalWrite(eastGreen, HIGH);
            trafficWest = LOW;
            step = 0;
            break;
        
        default:
            break;
        }
    }
    else if (digitalRead(westButton) == HIGH and (digitalRead(trafficWest)) == LOW){
        /* code */
        switch (step)
        {
        case 0: //East to yellow
            /* code */
            digitalWrite(eastYellow, HIGH);
            delay(changeDelay);
            step = 1;
            break;

        case 1: //East to red
            /* code */
            digitalWrite(eastYellow, LOW);
            digitalWrite(eastRed, HIGH);
            delay(changeDelay);
            step = 2;
            break;
        case 2: //Wait for traffic
            /* code */
            delay(flowTime);
            step = 3;
            break;
        case 3: //blink yellow west
            /* code */
            digitalWrite(westYellow, HIGH);
            delay(yellowBlinkTime);
            digitalWrite(westYellow, LOW);
            delay(yellowBlinkTime);
            delay(changeDelay);
            step = 4;
            break;
        case 4: //West to green
            /* code */
            digitalWrite(westRed, LOW);
            digitalWrite(westGreen, HIGH);
            trafficWest = HIGH;
            step = 0;
            break;
        }
    }


}











