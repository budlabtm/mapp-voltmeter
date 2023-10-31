#include <fsm.h>
#include <led.h>
#include <mqtt.h>

extern MQTTClient client;
extern EthernetClient ethClient;

void mqtt_init() {
  Serial.println("MQTT Setup init.");
  led_set(BLUE);
  client.begin(MQTT_HOST, ethClient);
}

void mqtt_setup(fsm_t *fsm) {
  Serial.println("MQTT Setup action.");
  if (client.connect(MQTT_USR, MQTT_USR, MQTT_PASS)) fsm_event_supply(fsm, 1);
  fsm_event_supply(fsm, FSM_EVENT_SAVE);
}

bool mqtt_publish(const char topic[], int payload) {
  return client.publish(topic, String(payload));
}