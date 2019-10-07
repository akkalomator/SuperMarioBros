#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <stack>
#include "states/state.hpp"

class State;

typedef std::shared_ptr<State> state_ptr;

class StateMachine
{

public:
  void addNewState(const state_ptr& newState);

  void back();

  void update();

private:
  std::stack<state_ptr> states_;
};


#endif
