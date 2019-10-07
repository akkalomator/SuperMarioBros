#include "credits-menu-state.hpp"

CreditsMenuState::CreditsMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<CreditsMenuPresenter> presenter) :
    State(machine),
    presenter_(std::move(presenter))
{

}

void CreditsMenuState::onStart()
{

}

void CreditsMenuState::update()
{

}

void CreditsMenuState::onStop()
{

}
