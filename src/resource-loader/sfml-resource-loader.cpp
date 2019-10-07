#include "sfml-resource-loader.hpp"

std::shared_ptr<sf::Font> SfmlResourceLoader::getSuperMarioFont()
{
  if (!superMarioFont_)
  {
    superMarioFont_ = std::unique_ptr<sf::Font>(new sf::Font);
    superMarioFont_->loadFromFile("../resources/fonts/mario-font.ttf");
  }
  return superMarioFont_;
}

std::shared_ptr<sf::Font> SfmlResourceLoader::superMarioFont_;
