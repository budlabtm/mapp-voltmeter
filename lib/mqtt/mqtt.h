#ifndef MQTT_H_
#define MQTT_H_

#define MQTT_HOST "192.168.0.29"
#define MQTT_USR "hfr-volt-device"
#define MQTT_PASS "mxlinux"

#include <MQTT.h>
#include <ethernet.h>

void mqtt_init();
void mqtt_setup(fsm_t *fsm);
bool mqtt_publish(const char topic[], int payload);

extern MQTTClient mqttClient;

#endif  // MQTT_H_