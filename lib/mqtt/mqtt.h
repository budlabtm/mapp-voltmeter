#ifndef MQTT_H_
#define MQTT_H_

#define MQTT_HOST "192.168.0.29"
#define MQTT_USR "hfr-volt-device"
#define MQTT_PASS "mxlinux"

#include <Ethernet.h>
#include <MQTT.h>
#include <fsm.h>

class MQTTState : public State {
 public:
  void setup();
  int8_t action();
  bool publish(const char topic[], int payload);
	bool connected();

 private:
  EthernetClient ethClient;
  MQTTClient mqttClient;
};

#endif  // MQTT_H_