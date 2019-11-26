#include "StateMachine.hpp"
#include "../exceptions/MoveBackException.hpp"
#include "../exceptions/ExitReqiredException.hpp"

StateMachine::StateMachine(std::shared_ptr<ViewFactory> &factory) :
    factory_(std::move(factory))
{
}

std::shared_ptr<ViewFactory> StateMachine::getPresenterFactory()
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


