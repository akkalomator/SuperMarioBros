#include "credits-menu-state.hpp"

CreditsMenuState::CreditsMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<CreditsMenuPresenter> presenter) :
    State(machine),
    presenter_(std::move(presenter))
{

}

void CreditsMenuState::onStart()
{
  presenter_->drawWindow();
}

void CreditsMenuState::update()
{
  presenter_->awaitExit();
}

void CreditsMenuState::onStop()
{

}
