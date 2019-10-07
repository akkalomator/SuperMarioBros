#ifndef PRESENTER_HPP
#define PRESENTER_HPP

#include "main-menu-submenues.hpp"

class MainMenuPresenter
{
public:
  virtual void drawMenu() const = 0;

  virtual MainMenuSubmenu getClickedSubmenu() const = 0;
};

#endif
