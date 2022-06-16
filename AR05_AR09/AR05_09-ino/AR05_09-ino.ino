#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

float sound;
float light;
float bright;
float hard;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void piezo_melody_delay(float seconds) {
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime);
}

void setup() {
  pinMode(6, INPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  sound = 0;
  light = 0;
  bright = 255;
  hard = 0;
  lcd.init();
  lcd.backlight();
}

void loop() {
  sound = digitalRead(6);
  lcd.setCursor(0, 0);
  lcd.print("Lite|Sound|Hard");
  lcd.setCursor(0, 1);
  lcd.print(String(light).toInt());
  lcd.setCursor(11, 1);
  lcd.print(String(hard).toInt());
  if (sound == 0) {
    light += 1;
  }
  hard = light / 5;
  if (hard == 1) {
    digitalWrite(10, HIGH);
  }
  if (hard == 2) {
    digitalWrite(9, HIGH);
  }
  if ((hard > 3) || (hard == 3)) {
    digitalWrite(5, HIGH);
    analogWrite(12, 255);
    tone(12, 131, 62.5);
    piezo_melody_delay(0.0625);
  }
  if (hard > 5) {
    noTone(12);
    tone(5, 131, 62.5);
    piezo_melody_delay(0.0625);
  }
  if (hard > 10) {
    noTone(12);
    tone(12, 1047, 62.5);
    piezo_melody_delay(0.0625);
  }
  if (!digitalRead(2)) {
    noTone(12);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(5, LOW);
    light = 0;
    lcd.clear();
  }
  if (!digitalRead(3)) {
    bright += 20;
    analogWrite(10, bright);
    analogWrite(9, bright);
    analogWrite(5, bright);
  }
  if (bright > 255) {
    bright = 20;
  }
}
