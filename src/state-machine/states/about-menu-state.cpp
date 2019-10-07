#include "about-menu-state.hpp"

AboutMenuState::AboutMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<AboutMenuPresenter> presenter) :
    State(machine),
    presenter_(std::move(presenter))
{
}

void AboutMenuState::onStart()
{

}

void AboutMenuState::update()
{

}

void AboutMenuState::onStop()
{

}
