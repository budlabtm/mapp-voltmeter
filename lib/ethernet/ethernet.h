#ifndef ETHERNET_H
#define ETHERNET_H

#include <Arduino.h>
#include <Ethernet.h>
#include <fsm.h>

void ethernet_init();
void ethernet_setup(fsm_t *fsm);

extern EthernetClient ethClient;
extern byte mac[];

#endif  // ETHERNET_H