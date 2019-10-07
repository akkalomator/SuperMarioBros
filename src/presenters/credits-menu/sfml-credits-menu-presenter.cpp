#include "sfml-credits-menu-presenter.hpp"
#include "../../resource-loader/sfml-resource-loader.hpp"
#include "../../exceptions/move-back-exception.hpp"

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
    window_->pollEvent(event);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    {
      while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {}
      std::string msg = "Return from Credits menu";
      throw MoveBackException(msg);
    }
  }
}
