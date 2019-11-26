#include "SfmlCreditsMenuView.hpp"
#include "../../resource-loader/SfmlResourceLoader.hpp"
#include "../../exceptions/MoveBackException.hpp"
#include "../../exceptions/ExitReqiredException.hpp"

SfmlCreditsMenuView::SfmlCreditsMenuView(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window)
{
}

void SfmlCreditsMenuView::drawWindow() const
{
  std::shared_ptr<sf::Font> font = SfmlResourceLoader::getSuperMarioFont();

  sf::Text title("Credits", *font, 50);
  title.setPosition(20, 20);

  sf::Text gameName("Super Marevo Bros", *font);
  gameName.setFillColor(sf::Color(255, 111, 0));
  gameName.setPosition(20, 100);

  sf::Text author("By akkalomator 2019", *font);
  author.setPosition(20, 160);

  sf::Text courseName("for SPbSTU c++", *font);
  courseName.setFillColor(sf::Color(255, 255, 255, 25));
  courseName.setPosition(20, 220);

  sf::Text love("Dedicated to Dasha with love", *font);
  love.setFillColor(sf::Color(255, 255, 255, 50));
  love.setPosition(20, 650);

  window_->clear();
  window_->draw(title);
  window_->draw(gameName);
  window_->draw(author);
  window_->draw(courseName);
  window_->draw(love);
  window_->display();
}

void SfmlCreditsMenuView::awaitExit() const
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
