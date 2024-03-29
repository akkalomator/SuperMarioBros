#include "SfmlAboutMenuView.hpp"
#include "../../exceptions/MoveBackException.hpp"
#include "../../resource-loader/SfmlResourceLoader.hpp"
#include "../../exceptions/ExitReqiredException.hpp"
#include <SFML/Graphics.hpp>

SfmlAboutMenuView::SfmlAboutMenuView(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window)
{
}

void SfmlAboutMenuView::drawWindow() const
{
  std::shared_ptr<sf::Font> font = SfmlResourceLoader::getSuperMarioFont();
  sf::Text title("ABOUT", *font, 50);
  title.setPosition(20, 20);
  sf::Text about("This is mario game\nUse arrows to walk\nUse space to jump\nHave fun :)", *font);
  about.setPosition(20, 100);

  window_->clear();
  window_->draw(title);
  window_->draw(about);
  window_->display();
}

void SfmlAboutMenuView::awaitExit() const
{
  sf::Event event{};
  while (true)
  {
    while (!window_->pollEvent(event))
    {}

    if (event.type == sf::Event::Closed)
    {
      std::string msg = "Exit from Main menu";
      throw ExitRequiredException();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
      while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {}
      std::string msg = "Return from About menu";
      throw MoveBackException(msg);
    }
  }
}
