#include <SFML/Graphics.hpp>
#include <memory>
#include "src/presenters/main-menu/SfmlMainMenuPresenter.hpp"
#include "src/state-machine/StateMachine.hpp"
#include "src/state-machine/states/main-menu/MainMenuState.hpp"
#include "src/exceptions/ExitReqiredException.hpp"
#include "src/presenters/factory/SfmlPresenterFactory.hpp"

int main()
{
  auto *window1 = new sf::RenderWindow(sf::VideoMode(1280, 720), "Super MAREVO bros");
  std::shared_ptr<sf::RenderWindow> window = std::shared_ptr<sf::RenderWindow>(window1);

  std::shared_ptr<PresenterFactory> factory(new SfmlPresenterFactory(window));

  std::unique_ptr<MainMenuPresenter> presenter = factory->getMainMenuPresenter();
  std::shared_ptr<StateMachine> machine(new StateMachine(factory));
  state_ptr state = state_ptr(new MainMenuState(machine, std::move(presenter)));
  machine->addNewState(state);

  while (window->isOpen())
  {
    try
    {
      machine->update();
    }
    catch (ExitRequiredException &e)
    {
      break;
    }
  }

  return 0;
}