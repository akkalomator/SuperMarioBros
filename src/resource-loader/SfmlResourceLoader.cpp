#include "SfmlResourceLoader.hpp"

std::shared_ptr<sf::Font> SfmlResourceLoader::getSuperMarioFont()
{
  if (!superMarioFont_)
  {
    superMarioFont_ = std::shared_ptr<sf::Font>(new sf::Font);
    superMarioFont_->loadFromFile("../resources/fonts/mario-font.ttf");
  }
  return superMarioFont_;
}

std::shared_ptr<sf::Texture> SfmlResourceLoader::getTexture(const std::string& path)
{
  auto it = textures.find(path);
  if (it == textures.end()) {
    std::shared_ptr<sf::Texture> texture = std::shared_ptr<sf::Texture>(new sf::Texture());
    texture->loadFromFile(path);
    textures.insert({path, texture});
  }
  return textures.find(path)->second;
}

std::shared_ptr<sf::Font> SfmlResourceLoader::superMarioFont_;
std::map<std::string, std::shared_ptr<sf::Texture>> SfmlResourceLoader::textures;
