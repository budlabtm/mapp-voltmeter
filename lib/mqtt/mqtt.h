#ifndef MQTT_H_
#define MQTT_H_

#include <Ethernet.h>
#include <MQTT.h>
#include <fsm.h>

struct credentials {
  const char *host;
  const char *username;
  const char *password;
};

class MQTTState : public State {
 public:
  MQTTState(credentials *creds);
  void setup();
  int8_t action();
  bool publish(const char topic[], int payload);
  bool connected();

 private:
  EthernetClient ethClient;
  MQTTClient mqttClient;
  credentials *creds;
};

#endif  // MQTT_H_