#ifndef PRESENTERFACTORY_HPP
#define PRESENTERFACTORY_HPP


#include "../main-menu/main-menu-presenter.hpp"
#include "../about-menu/about-menu-presenter.hpp"
#include "../credits-menu/credits-menu-presenter.hpp"

class PresenterFactory
{
public:
  virtual std::unique_ptr<MainMenuPresenter> getMainMenuPresenter() = 0;
  virtual std::unique_ptr<AboutMenuPresenter> getAboutMenuPresenter() = 0;
  virtual std::unique_ptr<CreditsMenuPresenter> getCreditsMenuPresenter() = 0;
};

#endif //PRESENTERFACTORY_HPP