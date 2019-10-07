#ifndef CREDITS_MENU_PRESENTER_HPP
#define CREDITS_MENU_PRESENTER_HPP

class CreditsMenuPresenter
{
public:
  virtual void drawWindow() const = 0;

  virtual void awaitExit() const = 0;
};

#endif //CREDITS_MENU_PRESENTER_HPP
