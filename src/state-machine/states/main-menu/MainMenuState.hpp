#ifndef MAIN_MENU_STATE_HPP
#define  MAIN_MENU_STATE_HPP

#include <bits/unique_ptr.h>
#include "../State.hpp"
#include "../../../presenters/main-menu/MainMenuPresenter.hpp"

class MainMenuState : public State
{
public:
  MainMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<MainMenuPresenter> presenter);

  void onStart() override;

  void update() override;

  void onStop() override;

private:
  std::unique_ptr<MainMenuPresenter> presenter_;
};


#endif // MAIN_MENU_STATE_HPP
