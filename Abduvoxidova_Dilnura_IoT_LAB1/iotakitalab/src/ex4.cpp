#include "Arduino.h"
#define LIGHT_PIN 33

#define BLUE_LED   14
#define GREEN_LED  27
#define YELLOW_LED 12
#define RED_LED    26

void setup() {
  Serial.begin(115200);

  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  int lightValue = analogRead(LIGHT_PIN);

  // Avval barcha LEDlarni o'chirish
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if (lightValue <= 1023) {
    digitalWrite(BLUE_LED, HIGH);
    Serial.println("band=BLUE");
  }
  else if (lightValue <= 2047) {
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("band=GREEN");
  }
  else if (lightValue <= 3071) {
    digitalWrite(YELLOW_LED, HIGH);
    Serial.println("band=YELLOW");
  }
  else {
    digitalWrite(RED_LED, HIGH);
    Serial.println("band=RED");
  }

  delay(200);
}
