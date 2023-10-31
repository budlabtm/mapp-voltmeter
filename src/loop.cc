#include <Arduino.h>
#include <fsm.h>
#include <led.h>
#include <loop.h>
#include <mqtt.h>

void loop_init() {
  Serial.println("Main loop setup.");
  led_set(GREEN);
}

void loop_action(fsm_t *fsm) {
  Serial.println("Main loop action.");

  if (!mqtt_publish("/test/1", analogRead(A0)) ||
      !mqtt_publish("/test/2", analogRead(A1))) {
    fsm_event_supply(fsm, 0);
    return;
  }

  fsm_event_supply(fsm, FSM_EVENT_SAVE);
}