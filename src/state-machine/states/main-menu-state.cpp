#include "main-menu-state.hpp"
#include "../../presenters/about-menu/about-menu-presenter.hpp"
#include "about-menu-state.hpp"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<MainMenuPresenter> presenter) :
    State(machine),
    presenter_(std::move(presenter))
{
}

void MainMenuState::onStart()
{
  presenter_->resetStylesToDefault();
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
      std::unique_ptr<AboutMenuPresenter> presenter = machine_->getFactory()->getAboutMenuPresenter();
      state_ptr aboutMenuState(new AboutMenuState(machine_, std::move(presenter)));
      machine_->addNewState(aboutMenuState);
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
