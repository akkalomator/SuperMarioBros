#include "MainMenuState.hpp"
#include "../about-menu/AboutMenuState.hpp"
#include "../credits/CreditsMenuState.hpp"
#include "../game-state/GameState.hpp"

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
      state_ptr gameState(new GameState(machine_));
      machine_->addNewState(gameState);
      break;
    }
    case ABOUT:
    {
      std::unique_ptr<AboutMenuPresenter> presenter = machine_->getPresenterFactory()->getAboutMenuPresenter();
      state_ptr aboutMenuState(new AboutMenuState(machine_, std::move(presenter)));
      machine_->addNewState(aboutMenuState);
      break;
    }
    case CREDITS:
    {
      std::unique_ptr<CreditsMenuPresenter> presenter = machine_->getPresenterFactory()->getCreditsMenuPresenter();
      state_ptr creditsMenuState(new CreditsMenuState(machine_, std::move(presenter)));
      machine_->addNewState(creditsMenuState);
      break;
    }
  }
}

void MainMenuState::onStop()
{
}
