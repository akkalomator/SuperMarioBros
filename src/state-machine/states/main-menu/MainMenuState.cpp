#include "MainMenuState.hpp"
#include "../about-menu/AboutMenuState.hpp"
#include "../credits/CreditsMenuState.hpp"
#include "../game-state/GameState.hpp"

MainMenuState::MainMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<MainMenuView> view) :
    State(machine),
    view_(std::move(view))
{
}

void MainMenuState::onStart()
{
  view_->resetStylesToDefault();
  view_->drawMenu();
}

void MainMenuState::update()
{
  switch (view_->getClickedSubmenu())
  {
    case START:
    {
      state_ptr gameState(new GameState(machine_));
      machine_->addNewState(gameState);
      break;
    }
    case ABOUT:
    {
      std::unique_ptr<AboutMenuView> view = machine_->getPresenterFactory()->getAboutMenuPresenter();
      state_ptr aboutMenuState(new AboutMenuState(machine_, std::move(view)));
      machine_->addNewState(aboutMenuState);
      break;
    }
    case CREDITS:
    {
      std::unique_ptr<CreditsMenuView> view = machine_->getPresenterFactory()->getCreditsMenuPresenter();
      state_ptr creditsMenuState(new CreditsMenuState(machine_, std::move(view)));
      machine_->addNewState(creditsMenuState);
      break;
    }
  }
}

void MainMenuState::onStop()
{
}
