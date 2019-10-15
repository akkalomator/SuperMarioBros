#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include "../StateMachine.hpp"

class StateMachine;

class State
{
public:
  explicit State(std::shared_ptr<StateMachine> machine);

  virtual void onStart() = 0;

  virtual void update() = 0;

  virtual void onStop() = 0;

protected:
  std::shared_ptr<StateMachine> machine_;
};

#endif // STATE_HPP
