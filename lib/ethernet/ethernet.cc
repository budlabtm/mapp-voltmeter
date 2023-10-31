#include <ethernet.h>
#include <fsm.h>
#include <led.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

void ethernet_init() {
  Serial.println("Ethernet Setup init.");
  led_set(RED);
}

void ethernet_setup(fsm_t *fsm) {
  Serial.println("Ethernet Setup action.");
  fsm_event_supply(fsm, Ethernet.begin(mac) != 0 ? 1 : FSM_EVENT_SAVE);
}