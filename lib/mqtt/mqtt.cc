#include <Arduino.h>
#include <ethernet.h>
#include <fsm.h>
#include <led.h>
#include <mqtt.h>

void mqtt_init() {
  led_set(BLUE);
  mqttClient.begin(MQTT_HOST, ethClient);
}

void mqtt_setup(fsm_t *fsm) {
  while (!mqttClient.connect(MQTT_USR, MQTT_USR, MQTT_PASS)) {
    Serial.println("MQTT try...");
		delay(1000);
	}

  fsm_event_supply(fsm, 1);
}

bool mqtt_publish(const char topic[], int payload) {
  return mqttClient.publish(topic, String(payload));
}

MQTTClient mqttClient;