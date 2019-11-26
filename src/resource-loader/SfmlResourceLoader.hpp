#ifndef SFML_RESOURCE_LOADER_HPP
#define SFML_RESOURCE_LOADER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class SfmlResourceLoader
{
public:
  static std::shared_ptr<sf::Font> getSuperMarioFont();

  static std::shared_ptr<sf::Texture> getTexture(const std::string& path);

private:
  static std::shared_ptr<sf::Font> superMarioFont_;
  static std::map<std::string, std::shared_ptr<sf::Texture>> textures;
};

#endif //SFML_RESOURCE_LOADER_HPP
