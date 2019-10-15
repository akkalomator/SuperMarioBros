#ifndef ABOUT_MENU_STATE_HPP
#define ABOUT_MENU_STATE_HPP

#include "../State.hpp"
#include "../../../presenters/about-menu/AboutMenuPresenter.hpp"

class AboutMenuState : public State
{
public:
  AboutMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<AboutMenuPresenter> presenter);

  void onStart() override;

  void update() override;

  void onStop() override;

private:
  std::unique_ptr<AboutMenuPresenter> presenter_;
};


#endif //ABOUT_MENU_STATE_HPP
