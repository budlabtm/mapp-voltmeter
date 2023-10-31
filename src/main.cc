#include <ethernet.h>
#include <fsm.h>
#include <led.h>
#include <loop.h>
#include <mqtt.h>

enum state { ETHER, MQTT, LOOP };
enum event { FAIL, OK };

fsm_state_t eth_s = {.setup = ethernet_init, .action = ethernet_setup};
fsm_state_t mqtt_s = {.setup = mqtt_init, .action = mqtt_setup};
fsm_state_t loop_s = {.setup = loop_init, .action = loop_action};

fsm_t fsm;

void setup() {
  Serial.begin(9600);
	
  led_init();
  fsm_init(&fsm);

  fsm_state_register(&fsm, ETHER, &eth_s);
  fsm_state_register(&fsm, MQTT, &mqtt_s);
  fsm_state_register(&fsm, LOOP, &loop_s);

  fsm_trans_register(&fsm, ETHER, OK, MQTT);
  fsm_trans_register(&fsm, MQTT, OK, LOOP);
  fsm_trans_register(&fsm, LOOP, FAIL, MQTT);
}

void loop() { fsm_exec(&fsm, ETHER); }