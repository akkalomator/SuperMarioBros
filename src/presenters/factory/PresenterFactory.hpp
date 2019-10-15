#ifndef PRESENTER_FACTORY_HPP
#define PRESENTER_FACTORY_HPP


#include "../main-menu/MainMenuPresenter.hpp"
#include "../about-menu/AboutMenuPresenter.hpp"
#include "../credits-menu/CreditsMenuPresenter.hpp"

class PresenterFactory
{
public:
  virtual std::unique_ptr<MainMenuPresenter> getMainMenuPresenter() = 0;

  virtual std::unique_ptr<AboutMenuPresenter> getAboutMenuPresenter() = 0;

  virtual std::unique_ptr<CreditsMenuPresenter> getCreditsMenuPresenter() = 0;
};

#endif //PRESENTER_FACTORY_HPP
