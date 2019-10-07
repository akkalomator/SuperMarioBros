#include "main-menu-state.hpp"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<MainMenuPresenter> presenter) :
    State(machine),
    presenter_(std::move(presenter))
{
}

void MainMenuState::onStart()
{
  presenter_->drawMenu();
}

void MainMenuState::update()
{
  switch (presenter_->getClickedSubmenu())
  {
    case START:
    {
      break;
    }
    case ABOUT:
    {
      break;
    }
    case CREDITS:
    {
      break;
    }
  }
}

void MainMenuState::onStop()
{

}
