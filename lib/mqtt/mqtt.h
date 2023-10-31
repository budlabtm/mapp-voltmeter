#ifndef MQTT_H_
#define MQTT_H_

#include <MQTT.h>
#include <ethernet.h>

#define MQTT_HOST "192.168.0.29"
#define MQTT_USR "hfr-volt-device"
#define MQTT_PASS "mxlinux"

void mqtt_init();
void mqtt_setup(fsm_t *fsm);
bool mqtt_publish(const char topic[], int payload);

MQTTClient client;

#endif  // MQTT_H_