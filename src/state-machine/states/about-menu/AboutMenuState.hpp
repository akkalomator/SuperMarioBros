#ifndef ABOUT_MENU_STATE_HPP
#define ABOUT_MENU_STATE_HPP

#include "../State.hpp"
#include "../../../views/about-menu/AboutMenuView.hpp"

class AboutMenuState : public State
{
public:
  AboutMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<AboutMenuView> view);

  void onStart() override;

  void update() override;

  void onStop() override;

private:
  std::unique_ptr<AboutMenuView> view_;
};


#endif //ABOUT_MENU_STATE_HPP
