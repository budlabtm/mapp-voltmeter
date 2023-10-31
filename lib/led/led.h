#ifndef LED_H
#define LED_H

#include <stdint.h>

#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255

#define RPIN 3
#define GPIN 5
#define BPIN 6

void led_init();
void led_set(uint8_t r, uint8_t g, uint8_t b);

#endif  // LED_H