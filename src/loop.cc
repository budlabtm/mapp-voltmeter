#include <Arduino.h>
#include <led.h>
#include <loop.h>
#include <mqtt.h>

LoopState::LoopState(MQTTState *_mqtt) : mqtt(_mqtt) {}

void LoopState::setup() { led_set(GREEN); }

int8_t LoopState::action() {
  if (this->mqtt->connected()) {
    this->mqtt->publish(TOP1, analogRead(VPIN1));
    this->mqtt->publish(TOP2, analogRead(VPIN2));
    delay(1000 / 200);
    FSM_REPEAT();
  } else
    FSM_THROW(0);
}