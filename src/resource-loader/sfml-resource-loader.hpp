#ifndef SFML_RESOURCE_LOADER_HPP
#define SFML_RESOURCE_LOADER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class SfmlResourceLoader
{
public:
  static std::shared_ptr<sf::Font> getSuperMarioFont();

private:
  static std::shared_ptr<sf::Font> superMarioFont_;
};

#endif //SFML_RESOURCE_LOADER_HPP
