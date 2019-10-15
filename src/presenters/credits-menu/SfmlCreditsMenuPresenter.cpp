#include "SfmlCreditsMenuPresenter.hpp"
#include "../../resource-loader/SfmlResourceLoader.hpp"
#include "../../exceptions/MoveBackException.hpp"
#include "../../exceptions/ExitReqiredException.hpp"

SfmlCreditsMenuPresenter::SfmlCreditsMenuPresenter(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window)
{
}

void SfmlCreditsMenuPresenter::drawWindow() const
{
  std::shared_ptr<sf::Font> font = SfmlResourceLoader::getSuperMarioFont();
  sf::Text text("akkalomator 2019", *font);

  window_->clear();
  window_->draw(text);
  window_->display();
}

void SfmlCreditsMenuPresenter::awaitExit() const
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
      std::string msg = "Return from Credits menu";
      throw MoveBackException(msg);
    }
  }
}
