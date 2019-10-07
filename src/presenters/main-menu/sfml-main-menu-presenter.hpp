#ifndef SFML_MAIN_MENU_PRESENTER_HPP
#define SFML_MAIN_MENU_PRESENTER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "main-menu-presenter.hpp"

class SfmlMainMenuPresenter : public MainMenuPresenter
{
  typedef std::unique_ptr<sf::Font> font_ptr;
  typedef std::unique_ptr<sf::Color> color_prt;
  typedef std::unique_ptr<sf::RectangleShape> rectangle_shape_ptr;
  typedef std::shared_ptr<sf::Text> text_ptr;

public:
  explicit SfmlMainMenuPresenter(std::shared_ptr<sf::RenderWindow> &window);

  void drawMenu() const override;

  MainMenuSubmenu getClickedSubmenu() const override;

private:
  std::shared_ptr<sf::RenderWindow> window_;
  float width_;
  float height_;
  rectangle_shape_ptr orangeRect_;
  font_ptr font_;
  color_prt defaultColour_;
  color_prt accentColour_;
  text_ptr super_;
  text_ptr marevo_;
  text_ptr bros_;
  text_ptr start_;
  text_ptr about_;
  text_ptr credits_;

  void resetStyles() const;

  void drawTitle() const;

  void drawSubmenues() const;

  text_ptr getFocused(int index) const;

  MainMenuSubmenu getCategory(int currentItem) const;
};


#endif
