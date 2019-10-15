#include "SfmlAboutMenuPresenter.hpp"
#include "../../exceptions/MoveBackException.hpp"
#include "../../resource-loader/SfmlResourceLoader.hpp"
#include "../../exceptions/ExitReqiredException.hpp"
#include <SFML/Graphics.hpp>

SfmlAboutMenuPresenter::SfmlAboutMenuPresenter(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window)
{
}

void SfmlAboutMenuPresenter::drawWindow() const
{
  std::shared_ptr<sf::Font> font = SfmlResourceLoader::getSuperMarioFont();
  sf::Text text("ABOUT", *font);

  window_->clear();
  window_->draw(text);
  window_->display();
}

void SfmlAboutMenuPresenter::awaitExit() const
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
