#ifndef FSM_H
#define FSM_H

#define FSM_THROW(event) return event;
#define FSM_REPEAT() return -1;
#define FSM_STOP() return -2;
#define FSM_EVENTS 2

#include <stdint.h>

class State {
 public:
  State *next(int8_t event);
  void addTransition(int8_t event, State *next);

  virtual void setup();
  virtual int8_t action();

 private:
  State *transitions[FSM_EVENTS];
};

class FSM {
 public:
  void run(State *root);

 private:
  State *state;
};

#endif  // FSM_H