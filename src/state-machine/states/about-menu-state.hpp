#ifndef ABOUTMENUSTATE_HPP
#define ABOUTMENUSTATE_HPP

#include "state.hpp"
#include "../../presenters/about-menu/about-menu-presenter.hpp"

class AboutMenuState : public State
{
public:
  AboutMenuState (std::shared_ptr<StateMachine> &machine, std::unique_ptr<AboutMenuPresenter> presenter);

  void onStart() override;

  void update() override;

  void onStop() override;

private:
  std::unique_ptr<AboutMenuPresenter> presenter_;
};


#endif //ABOUTMENUSTATE_HPP
