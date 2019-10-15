#ifndef MAIN_MENU_PRESENTER_HPP
#define MAIN_MENU_PRESENTER_HPP

#include "MainMenuSubmenues.hpp"

class MainMenuPresenter
{
public:
  virtual void resetStylesToDefault() const = 0;

  virtual void drawMenu() const = 0;

  virtual MainMenuSubmenu getClickedSubmenu() const = 0;
};

#endif // MAIN_MENU_PRESENTER_HPP
