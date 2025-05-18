#include <Arduino.h>

/*
Traffic Light
Projekt 5 - Eine Verkehrsampel
*/

// Definiert die Pins, mit denen die Tasten und LEDs verbunden sind:
#define westButton 5
#define eastButton 13
#define westRed 4
#define westYellow 3
#define westGreen 2
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500 // Lässt die gelbe LED 0,5 s blinken
int flowTime = 4000; // Zeitraum, in dem der Verkehr fliesst
int changeDelay = 2000; // Zeitraum zwischen Farbwechseln
int step = 0;

// --- Edge Detection ---
boolean trafficWest = true; // West = true, Ost = false
boolean lastEastButtonState = false;
boolean lastWestButtonState = false;
boolean eastRequest = false;      // Trigger from east
boolean westRequest = false;      // Trigger from west
// Richtet die digitalen E/A-Pins ein
void setup() {
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
  // ---- Detect Button Triggers ----
  bool currentEast = digitalRead(eastButton);
  bool currentWest = digitalRead(westButton);

  if (currentEast == HIGH and lastEastButtonState == LOW and trafficWest and (step == 0 or step == -1)) {
    eastRequest = true;
    westRequest = false;
  }
  if (currentWest == HIGH and lastWestButtonState == LOW and not trafficWest and (step == 0 or step == -1)) {
    westRequest = true;
    eastRequest = false;
  }

  lastEastButtonState = currentEast;
  lastWestButtonState = currentWest;
    if (eastRequest){
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
            digitalWrite(westGreen, LOW);
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
        for (int i = 0; i < changeDelay / (2 * yellowBlinkTime); i++) {
            digitalWrite(eastYellow, HIGH);
            delay(yellowBlinkTime);
            digitalWrite(eastYellow, LOW);
            delay(yellowBlinkTime);
            }
            step = 4;
            break;
        case 4: //East to green
            /* code */
            digitalWrite(eastRed, LOW);
            digitalWrite(eastGreen, HIGH);
            trafficWest = false;
            eastRequest = false;
            step = -1; // idle state until west button pressed
            break;

        default:
            break;
        }
    }
    else if (westRequest){
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
            digitalWrite(eastGreen, LOW);
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
        for (int i = 0; i < changeDelay / (2 * yellowBlinkTime); i++) {
            digitalWrite(westYellow, HIGH);
            delay(yellowBlinkTime);
            digitalWrite(westYellow, LOW);
            delay(yellowBlinkTime);
             }
            step = 4;   
            break;
        case 4: //West to green
            /* code */
            digitalWrite(westRed, LOW);
            digitalWrite(westGreen, HIGH);
            trafficWest = true;
            westRequest = false;
            step = -1; // idle state until west button pressed
            break;
        }
    }

  // Reset to idle if no request but light is green
  if (step == -1 and not eastRequest and not westRequest) {
    step = 0;
  }
}











