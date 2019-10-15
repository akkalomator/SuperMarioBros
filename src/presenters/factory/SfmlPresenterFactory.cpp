#include "SfmlPresenterFactory.hpp"
#include "../main-menu/SfmlMainMenuPresenter.hpp"
#include "../about-menu/SfmlAboutMenuPresenter.hpp"
#include "../credits-menu/SfmlCreditsMenuPresenter.hpp"

SfmlPresenterFactory::SfmlPresenterFactory(std::shared_ptr<sf::RenderWindow> &window) :
    window_(window)
{
}

std::unique_ptr<MainMenuPresenter> SfmlPresenterFactory::getMainMenuPresenter()
{
  return std::unique_ptr<MainMenuPresenter>(new SfmlMainMenuPresenter(window_));
}

std::unique_ptr<AboutMenuPresenter> SfmlPresenterFactory::getAboutMenuPresenter()
{
  return std::unique_ptr<AboutMenuPresenter>(new SfmlAboutMenuPresenter(window_));
}

std::unique_ptr<CreditsMenuPresenter> SfmlPresenterFactory::getCreditsMenuPresenter()
{
  return std::unique_ptr<CreditsMenuPresenter>(new SfmlCreditsMenuPresenter(window_));
}
