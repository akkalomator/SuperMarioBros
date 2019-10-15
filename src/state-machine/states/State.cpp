#include "State.hpp"

State::State(std::shared_ptr<StateMachine> machine) :
  machine_(std::move(machine))
{
}

