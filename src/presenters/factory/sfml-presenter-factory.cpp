#include "sfml-presenter-factory.hpp"
#include "../main-menu/sfml-main-menu-presenter.hpp"
#include "../about-menu/sfml_about_menu_presenter.hpp"
#include "../credits-menu/sfml-credits-menu-presenter.hpp"

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
