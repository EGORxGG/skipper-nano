#include <EasyHID.h>

void setup() {
//  delay(30000);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  HID.begin();
}

void loop() {
  if (!HID.isConnected()) {
    delay(500);
    Serial.println("Trying to connect");
    HID.begin();
    HID.tick();
  }
  keyboardF1();
  connectedBlink();
  HID.tick();
}

void keyboardF1() {
  static uint32_t timer;
  if (HID.isConnected() && millis() - timer >= 5000) {
    timer = millis();
    Serial.println("keyF1");
    Keyboard.click(KEY_F1);
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
