#ifndef CREDITS_MENU_STATE_HPP
#define CREDITS_MENU_STATE_HPP


#include "../State.hpp"
#include "../../../views/credits-menu/CreditsMenuView.hpp"

class CreditsMenuState : public State
{
public:

  explicit CreditsMenuState(std::shared_ptr<StateMachine> &machine, std::unique_ptr<CreditsMenuView> view);

  void onStart() override;

  void update() override;

  void onStop() override;

private:

  std::unique_ptr<CreditsMenuView> view_;
};


#endif //CREDITS_MENU_STATE_HPP
