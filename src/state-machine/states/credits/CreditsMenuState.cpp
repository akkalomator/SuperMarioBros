#include "CreditsMenuState.hpp"

CreditsMenuState::CreditsMenuState(std::shared_ptr<StateMachine> &machine,
                                   std::unique_ptr<CreditsMenuView> view) :
    State(machine),
    view_(std::move(view))
{
}

void CreditsMenuState::onStart()
{
  view_->drawWindow();
}

void CreditsMenuState::update()
{
  view_->awaitExit();
}

void CreditsMenuState::onStop()
{
}
