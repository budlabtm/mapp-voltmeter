#include <Ethernet.h>
#include <SPI.h>
#include <ethernet.h>
#include <fsm.h>
#include <led.h>

void ethernet_init() { led_set(RED); }

void ethernet_setup(fsm_t *fsm) {
  Serial.println("Ethernet try...");

  if (Ethernet.begin(mac) == 0) {
    fsm_event_supply(fsm, 1);
}

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
EthernetClient ethClient;