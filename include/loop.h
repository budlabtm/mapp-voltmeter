#ifndef LOOP_H
#define LOOP_H

#define TOP1 "/test/a0"
#define TOP2 "/test/a1"

#define VPIN1 A0
#define VPIN2 A1

#include <fsm.h>

void loop_init();
void loop_action(fsm_t *fsm);

#endif  // LOOP_H