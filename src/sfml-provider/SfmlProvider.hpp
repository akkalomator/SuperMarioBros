#ifndef SUPERMARIOBROS3_SFMLPROVIDER_HPP
#define SUPERMARIOBROS3_SFMLPROVIDER_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class SfmlProvider
{
public:
  static const int WIDTH;
  static const int HEIGHT;

  static std::shared_ptr<sf::RenderWindow> getWindow();
private:
  static std::shared_ptr<sf::RenderWindow> window_;
};


#endif //SUPERMARIOBROS3_SFMLPROVIDER_HPP
