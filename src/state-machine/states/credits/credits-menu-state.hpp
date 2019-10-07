#ifndef CREDITS_MENU_STATE_HPP
#define CREDITS_MENU_STATE_HPP


#include "../state.hpp"
#include "../../../presenters/credits-menu/credits-menu-presenter.hpp"

class CreditsMenuState : public State
{
public:

  explicit CreditsMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<CreditsMenuPresenter> presenter);

  void onStart() override;

  void update() override;

  void onStop() override;

private:

  std::unique_ptr<CreditsMenuPresenter> presenter_;
};


#endif //CREDITS_MENU_STATE_HPP
