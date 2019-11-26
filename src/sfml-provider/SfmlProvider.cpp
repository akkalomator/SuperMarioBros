
#include "SfmlProvider.hpp"

std::shared_ptr<sf::RenderWindow> SfmlProvider::getWindow()
{
  if (SfmlProvider::window_ == 0) {
    SfmlProvider::window_ = std::shared_ptr<sf::RenderWindow>(
        new sf::RenderWindow(
            sf::VideoMode(WIDTH, HEIGHT),
            "Super MAREVO bros"
        )
    );
  }
  return window_;
}

const int SfmlProvider::WIDTH = 1280;
const int SfmlProvider::HEIGHT = 720;

std::shared_ptr<sf::RenderWindow> SfmlProvider::window_ = 0;
