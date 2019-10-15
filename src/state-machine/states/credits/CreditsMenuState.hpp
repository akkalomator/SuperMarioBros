#ifndef CREDITS_MENU_STATE_HPP
#define CREDITS_MENU_STATE_HPP


#include "../State.hpp"
#include "../../../presenters/credits-menu/CreditsMenuPresenter.hpp"

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
