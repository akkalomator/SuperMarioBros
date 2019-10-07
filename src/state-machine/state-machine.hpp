#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <stack>
#include "states/state.hpp"
#include "../presenters/factory/presenter-factory.hpp"

class State;

typedef std::shared_ptr<State> state_ptr;

class StateMachine
{
public:
  StateMachine(std::shared_ptr<PresenterFactory> &factory);

  std::shared_ptr<PresenterFactory> getPresenterFactory();

  void addNewState(const state_ptr &newState);

  void back();

  void update();

private:
  std::shared_ptr<PresenterFactory> factory_;

  std::stack<state_ptr> states_;
};


#endif // STATEMACHINE_HPP
