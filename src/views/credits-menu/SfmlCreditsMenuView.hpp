#ifndef SFML_CREDITS_MENU_PRESENTER_HPP
#define SFML_CREDITS_MENU_PRESENTER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "CreditsMenuView.hpp"

class SfmlCreditsMenuView : public CreditsMenuView
{
public:
  explicit SfmlCreditsMenuView(std::shared_ptr<sf::RenderWindow> &window);

  void drawWindow() const override;

  void awaitExit() const override;

private:
  std::shared_ptr<sf::RenderWindow> window_;
};

#endif //SFML_CREDITS_MENU_PRESENTER_HPP
