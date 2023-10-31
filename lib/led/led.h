#ifndef LED_H
#define LED_H

#include <stdint.h>

#define RPIN 3
#define GPIN 5
#define BPIN 6

#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255

void led_init();
void led_set(uint8_t red, uint8_t green, uint8_t blue);

#endif  // LED_H