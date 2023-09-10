#include <EasyHID.h>

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  keyboardF1();
  connectedBlink();
}

void keyboardF1() {
  static uint32_t timer;
  if (HID.isConnected() && millis() - timer >= 5000) {
    HID.begin();
    Serial.println("keyF1");
    Keyboard.click(KEY_F1);
    HID.end();
  }
}

void connectedBlink() {
  static uint32_t timer;
  if (millis() - timer >= 1000) {
    timer = millis();
    Serial.println("blink");
    digitalWrite(13, !digitalRead(13));
  }
}
