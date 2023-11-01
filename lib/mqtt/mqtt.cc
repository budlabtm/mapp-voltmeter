#include <led.h>
#include <mqtt.h>

void MQTTState::setup() {
  led_set(BLUE);
  this->mqttClient.begin(MQTT_HOST, this->ethClient);
}

int8_t MQTTState::action() {
  if (this->mqttClient.connect(MQTT_USR, MQTT_USR, MQTT_PASS)) {
    FSM_THROW(1);
  } else
    FSM_REPEAT();
}

bool MQTTState::publish(const char topic[], int payload) {
  return this->mqttClient.publish(topic, String(payload));
}

bool MQTTState::connected() { return this->mqttClient.connected(); }
