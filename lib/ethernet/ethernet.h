#ifndef ETHERNET_H
#define ETHERNET_H

#include <fsm.h>

class EthernetState : public State {
 public:
  void setup();
  int8_t action();

 private:
  uint8_t MAC[6] = {0xDE, 0xAD, 0xBE, 0xAF, 0xFE, 0xED};
};

#endif  // ETHERNET_H