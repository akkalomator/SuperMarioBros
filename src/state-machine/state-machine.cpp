#include "state-machine.hpp"
#include "../exceptions/MoveBackException.hpp"
#include "../exceptions/ExitRequiredException.hpp"

void StateMachine::addNewState(const state_ptr &newState)
{
  states_.push(newState);
  states_.top()->onStart();
}

void StateMachine::back()
{
  states_.top()->onStop();
  states_.pop();
  if (states_.empty()) {
    std::string msg = "All windows are closed";
    throw ExitRequiredException(msg);
  }
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


