#include <ethernet.h>
#include <fsm.h>
#include <led.h>
#include <loop.h>
#include <mqtt.h>

enum event { FAIL, OK };

credentials creds = {
    .host = "localhost", .username = "username", .password = "password"};

FSM fsm;
EthernetState ethernet_s;
MQTTState mqtt_s{&creds};
LoopState loop_s{&mqtt_s};

void setup() {
  Serial.begin(9600);
  led_init();

  ethernet_s.addTransition(OK, &mqtt_s);
  mqtt_s.addTransition(OK, &loop_s);
  mqtt_s.addTransition(FAIL, &ethernet_s);
  loop_s.addTransition(FAIL, &mqtt_s);
}

void loop() { fsm.run(&ethernet_s); }