#include "AboutMenuState.hpp"

AboutMenuState::AboutMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<AboutMenuView> view) :
    State(machine),
    view_(std::move(view))
{
}

void AboutMenuState::onStart()
{
  view_->drawWindow();
}

void AboutMenuState::update()
{
  view_->awaitExit();
}

void AboutMenuState::onStop()
{
}
