#ifndef ABOUT_MENU_PRESENTER_HPP
#define ABOUT_MENU_PRESENTER_HPP

#include <SFML/Graphics.hpp>

class AboutMenuView
{
public:
  virtual void drawWindow() const = 0;

  virtual void awaitExit() const = 0;
};

#endif //ABOUT_MENU_PRESENTER_HPP
