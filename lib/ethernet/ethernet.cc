#include <Ethernet.h>
#include <SPI.h>
#include <ethernet.h>
#include <led.h>

void EthernetState::setup() { led_set(RED); }

int8_t EthernetState::action() {
  if (Ethernet.begin(this->MAC)) {
    FSM_THROW(1);
  } else {
    FSM_REPEAT();
  }
}
