#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "src/presenters/main-menu/sfml-main-menu-presenter.hpp"
#include "src/exceptions/MoveBackException.hpp"

int main()
{
  auto* window1 = new sf::RenderWindow(sf::VideoMode(1280, 720), "Super MAREVO bros");
  std::shared_ptr<sf::RenderWindow> window = std::shared_ptr<sf::RenderWindow>(window1);

  SfmlMainMenuPresenter presenter(window);
  presenter.drawMenu();

  while (window->isOpen())
  {
    try {
      std::cout << presenter.getClickedSubmenu();
    } catch (MoveBackException &e) {
      break;
    }
  }

  return 0;
}