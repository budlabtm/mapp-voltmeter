#include <Arduino.h>
#include <fsm.h>

void fsm_init(fsm_t *fsm) {
  fsm->state = 0;
  fsm->event = -1;

  for (int i = 0; i < FSM_STATES; i++)
    for (int j = 0; j < FSM_EVENTS; j++) fsm->transitions[i][j] = -1;
}

void fsm_event_supply(fsm_t *fsm, int8_t event) { fsm->event = event; }

void fsm_state_register(fsm_t *fsm, int8_t stateId, fsm_state_t *state) {
  fsm->states[stateId] = state;
}

void fsm_trans_register(fsm_t *fsm, int8_t source, int8_t event,
                        int8_t destination) {
  fsm->transitions[source][event] = destination;
}

void fsm_exec(fsm_t *fsm, int8_t root) {
  fsm->state = root;

  while (1) {
    fsm->states[fsm->state]->setup();

    while (fsm->event == -1) fsm->states[fsm->state]->action(fsm);

    fsm->state = fsm->transitions[fsm->state][fsm->event];
    fsm->event = -1;
  }
}