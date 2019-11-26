#ifndef MAIN_MENU_STATE_HPP
#define  MAIN_MENU_STATE_HPP

#include <bits/unique_ptr.h>
#include "../State.hpp"
#include "../../../views/main-menu/MainMenuView.hpp"

class MainMenuState : public State
{
public:
  MainMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<MainMenuView> view);

  void onStart() override;

  void update() override;

  void onStop() override;

private:
  std::unique_ptr<MainMenuView> view_;
};


#endif // MAIN_MENU_STATE_HPP
