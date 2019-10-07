#ifndef SFMLRESOURCELOADER_HPP
#define SFMLRESOURCELOADER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class SfmlResourceLoader
{
public:
  static std::shared_ptr<sf::Font> getSuperMarioFont();

private:
  static std::shared_ptr<sf::Font> superMarioFont_;
};

#endif //SFMLRESOURCELOADER_HPP
