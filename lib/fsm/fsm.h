#ifndef FSM_H
#define FSM_H

#include <stdint.h>

#define FSM_STATES_MAX 3
#define FSM_EVENTS_MAX 2
#define FSM_EVENT_STOP -2
#define FSM_EVENT_SAVE -1

typedef struct fsm fsm_t;
typedef struct fsm_state fsm_state_t;

struct fsm_state {
  void (*setup)();
  void (*action)(fsm_t *fsm);
};

struct fsm {
  int8_t state;
  int8_t event;
  struct fsm_state *states[FSM_STATES_MAX];
  int8_t transitions[FSM_STATES_MAX][FSM_EVENTS_MAX];
};

void fsm_init(fsm_t *fsm);
void fsm_event_supply(fsm_t *fsm, int8_t event);
void fsm_state_register(fsm_t *fsm, int8_t stateId, fsm_state_t *state);
void fsm_trans_register(fsm_t *fsm, int8_t source, int8_t event,
                        int8_t destination);
void fsm_exec(fsm_t *fsm, int8_t root);

#endif  // FSM_H