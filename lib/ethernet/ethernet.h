#ifndef ETHERNET_H
#define ETHERNET_H

#include <Ethernet.h>
#include <SPI.h>
#include <fsm.h>

void ethernet_init();
void ethernet_setup(fsm_t *fsm);

EthernetClient ethClient;

#endif  // ETHERNET_H