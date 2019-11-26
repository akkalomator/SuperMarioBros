#include <SFML/Graphics.hpp>
#include <memory>
#include "src/views/main-menu/SfmlMainMenuView.hpp"
#include "src/state-machine/StateMachine.hpp"
#include "src/state-machine/states/main-menu/MainMenuState.hpp"
#include "src/exceptions/ExitReqiredException.hpp"
#include "src/views/factory/SfmlViewFactory.hpp"
#include "src/sfml-provider/SfmlProvider.hpp"

int main()
{
  std::shared_ptr<sf::RenderWindow> window = SfmlProvider::getWindow();

  std::shared_ptr<ViewFactory> factory(new SfmlViewFactory(window));

  std::unique_ptr<MainMenuView> view = factory->getMainMenuPresenter();
  std::shared_ptr<StateMachine> machine(new StateMachine(factory));
  state_ptr state = state_ptr(new MainMenuState(machine, std::move(view)));
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