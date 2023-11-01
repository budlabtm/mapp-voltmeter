#include <Arduino.h>
#include <fsm.h>

State *State::next(int8_t event) { return this->transitions[event]; }

void State::addTransition(int8_t event, State *next) {
  this->transitions[event] = next;
}

void FSM::run(State *root) {
  int8_t event = -1;
  this->state = root;

  while (1) {
    this->state->setup();

    while ((event = this->state->action()) == -1) {
    }

    if (event == -2)
      return;
    else
      this->state = this->state->next(event);
  }
}
