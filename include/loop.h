#ifndef LOOP_H
#define LOOP_H

#define TOP1 "/lab/hfr/volt/c0"
#define TOP2 "/lab/hfr/volt/c1"
#define VPIN1 A0
#define VPIN2 A1

#include <fsm.h>
#include <mqtt.h>

class LoopState : public State {
 public:
  LoopState(MQTTState *mqtt);
  void setup();
  int8_t action();

 private:
  MQTTState *mqtt;
};

#endif  // LOOP_H