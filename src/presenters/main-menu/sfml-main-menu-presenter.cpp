#include "sfml-main-menu-presenter.hpp"
#include "../../exceptions/move-back-exception.hpp"
#include <memory>

SfmlMainMenuPresenter::SfmlMainMenuPresenter(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window),
    width_(window->getSize().x),
    height_(window->getSize().y),
    orangeRect_(rectangle_shape_ptr(new sf::RectangleShape())),
    defaultColour_(color_prt(new sf::Color(255, 255, 255))),
    accentColour_(color_prt(new sf::Color(255, 130, 130)))
{
  font_ = font_ptr(new sf::Font());
  font_->loadFromFile("../resources/fonts/mario-font.ttf");

  super_ = text_ptr(new sf::Text("SUPER", *font_, 60));
  marevo_ = text_ptr(new sf::Text("MAREVO", *font_, 60));
  bros_ = text_ptr(new sf::Text("BROS", *font_, 60));

  start_ = text_ptr(new sf::Text("START", *font_, 30));
  about_ = text_ptr(new sf::Text("ABOUT", *font_, 30));
  credits_ = text_ptr(new sf::Text("CREDITS", *font_, 30));
}

void SfmlMainMenuPresenter::drawMenu() const
{
  window_->clear();
  drawTitle();
  drawSubmenues();
  window_->display();
}

MainMenuSubmenu SfmlMainMenuPresenter::getClickedSubmenu() const
{
  sf::Event event{};

  int currentItem = 0;

  bool selected = false;
  while (!selected)
  {
    window_->pollEvent(event);

    if (event.type == sf::Event::KeyPressed)
    {
      switch (event.key.code)
      {
        case sf::Keyboard::Escape:
        {
          std::string msg = "Return from Main Menu";
          throw MoveBackException(msg);
        }
        case sf::Keyboard::Space:
        case sf::Keyboard::Return:
        {
          selected = true;
          break;
        }
        case sf::Keyboard::W:
        case sf::Keyboard::Up:
        {
          text_ptr current = getFocused(currentItem);
          current->setFillColor(*defaultColour_);
          currentItem = currentItem == 0 ? 0 : currentItem - 1;
          current = getFocused(currentItem);
          current->setFillColor(*accentColour_);
          drawMenu();
          while (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {}
          break;
        }
        case sf::Keyboard::S:
        case sf::Keyboard::Down:
        {
          text_ptr current = getFocused(currentItem);
          current->setFillColor(*defaultColour_);
          currentItem = currentItem == 2 ? 2 : currentItem + 1;
          current = getFocused(currentItem);
          current->setFillColor(*accentColour_);
          drawMenu();
          while (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {}
          break;
        }
        default:
        {
          break;
        }
      }
    }
  }
  return getCategory(currentItem);
}

MainMenuSubmenu SfmlMainMenuPresenter::getCategory(int currentItem) const
{
  switch (currentItem) {
    case 0:
    {
      return START;
    }
    case 1:
    {
      return ABOUT;
    }
    case 2:
    {
      return CREDITS;
    }
    default:
    {
      throw std::invalid_argument("Index of items out of range");
    }
  }
}

void SfmlMainMenuPresenter::drawTitle() const
{
  window_->draw(*orangeRect_);
  window_->draw(*super_);
  window_->draw(*marevo_);
  window_->draw(*bros_);
}

void SfmlMainMenuPresenter::drawSubmenues() const
{
  window_->draw(*start_);
  window_->draw(*about_);
  window_->draw(*credits_);
}

SfmlMainMenuPresenter::text_ptr SfmlMainMenuPresenter::getFocused(int index) const
{
  switch (index)
  {
    case 0:
    {
      return start_;
    }
    case 1:
    {
      return about_;
    }
    case 2:
    {
      return credits_;
    }
    default:
    {
      throw std::invalid_argument("Index out of items range");
    }
  }
}

void SfmlMainMenuPresenter::resetStylesToDefault() const
{
  orangeRect_->setFillColor(sf::Color(213, 75, 0));
  orangeRect_->setPosition(width_ / 20 * 7, height_ / 20 * 3);
  orangeRect_->setSize({width_ / 20 * 8, height_ / 20 * 4});

  super_->setPosition(width_ / 20 * 7, height_ / 20 * 3);
  marevo_->setPosition(width_ / 20 * 7, height_ / 20 * 5);
  bros_->setPosition(width_ / 20 * 7, height_ / 20 * 7);
  super_->setFillColor(*defaultColour_);
  marevo_->setFillColor(*defaultColour_);
  bros_->setFillColor(*defaultColour_);

  start_->setPosition(width_ / 20 * 8, height_ / 20 * 12);
  about_->setPosition(width_ / 20 * 8, height_ / 20 * 14);
  credits_->setPosition(width_ / 20 * 8, height_ / 20 * 16);
  start_->setFillColor(*accentColour_);
  about_->setFillColor(*defaultColour_);
  credits_->setFillColor(*defaultColour_);
}
