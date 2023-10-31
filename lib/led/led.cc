#include <Arduino.h>
#include <led.h>

void led_init() {
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
}

void led_set(uint8_t red, uint8_t green, uint8_t blue) {
  analogWrite(RPIN, red);
  analogWrite(GPIN, green);
  analogWrite(BPIN, blue);
}
