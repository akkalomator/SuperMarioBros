#include "SfmlViewFactory.hpp"
#include "../main-menu/SfmlMainMenuView.hpp"
#include "../about-menu/SfmlAboutMenuView.hpp"
#include "../credits-menu/SfmlCreditsMenuView.hpp"

SfmlViewFactory::SfmlViewFactory(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window)
{
}

std::unique_ptr<MainMenuView> SfmlViewFactory::getMainMenuPresenter()
{
  return std::unique_ptr<MainMenuView>(new SfmlMainMenuView(window_));
}

std::unique_ptr<AboutMenuView> SfmlViewFactory::getAboutMenuPresenter()
{
  return std::unique_ptr<AboutMenuView>(new SfmlAboutMenuView(window_));
}

std::unique_ptr<CreditsMenuView> SfmlViewFactory::getCreditsMenuPresenter()
{
  return std::unique_ptr<CreditsMenuView>(new SfmlCreditsMenuView(window_));
}
