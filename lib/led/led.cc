#include "led.h"

#include <Arduino.h>

void led_init() {
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
}

void led_set(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(RPIN, r);
  analogWrite(GPIN, g);
  analogWrite(BPIN, b);
}
