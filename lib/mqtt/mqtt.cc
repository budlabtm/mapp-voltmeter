#include <led.h>
#include <mqtt.h>

MQTTState::MQTTState(credentials *creds) : creds(creds) {}

void MQTTState::setup() {
  led_set(BLUE);
  this->mqttClient.begin(creds->host, this->ethClient);
}

int8_t MQTTState::action() {
  if (this->mqttClient.connect(creds->username, creds->username,
                               creds->password)) {
    FSM_THROW(1);
  } else
    FSM_REPEAT();
}

bool MQTTState::publish(const char topic[], int payload) {
  return this->mqttClient.publish(topic, String(payload));
}

bool MQTTState::connected() { return this->mqttClient.connected(); }
