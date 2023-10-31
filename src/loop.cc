#include <Arduino.h>
#include <fsm.h>
#include <led.h>
#include <loop.h>
#include <mqtt.h>

void loop_init() { led_set(GREEN); }

void loop_action(fsm_t *fsm) {
  if (!mqtt_publish(TOP1, analogRead(VPIN1)) ||
      !mqtt_publish(TOP2, analogRead(VPIN2)))
    fsm_event_supply(fsm, 0);
}