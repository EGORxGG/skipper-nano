#include <EasyHID.h>

void setup() {
  HID.begin();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  keyboardF1();
  connectedBlink();
  HID.tick();
}

void keyboardF1() {
  static uint32_t timer;
  if (millis() - timer >= 5000) {
    Serial.println("keyF1");
    timer = millis();
    Keyboard.click(KEY_F1);
  }
}

void connectedBlink() {
  static uint32_t timer;
  if (millis() - timer >= 1000) {
    Serial.println("blink");
    timer = millis();
    digitalWrite(13, !digitalRead(13));
  }
}
