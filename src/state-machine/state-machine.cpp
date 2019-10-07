#include "state-machine.hpp"
#include "../exceptions/move-back-exception.hpp"
#include "../exceptions/exit-required-exception.hpp"

StateMachine::StateMachine(std::shared_ptr<PresenterFactory> &factory) :
    factory_(std::move(factory))
{
}

std::shared_ptr<PresenterFactory> StateMachine::getPresenterFactory()
{
  return factory_;
}

void StateMachine::addNewState(const state_ptr &newState)
{
  states_.push(newState);
  states_.top()->onStart();
}

void StateMachine::back()
{
  states_.top()->onStop();
  states_.pop();
  if (states_.empty())
  {
    std::string msg = "All windows are closed";
    throw ExitRequiredException(msg);
  }
  states_.top()->onStart();
}

void StateMachine::update()
{
  try
  {
    states_.top()->update();
  }
  catch (MoveBackException &e)
  {
    back();
  }
}


