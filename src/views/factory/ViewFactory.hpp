#ifndef PRESENTER_FACTORY_HPP
#define PRESENTER_FACTORY_HPP


#include "../main-menu/MainMenuView.hpp"
#include "../about-menu/AboutMenuView.hpp"
#include "../credits-menu/CreditsMenuView.hpp"

class ViewFactory
{
public:
  virtual std::unique_ptr<MainMenuView> getMainMenuPresenter() = 0;

  virtual std::unique_ptr<AboutMenuView> getAboutMenuPresenter() = 0;

  virtual std::unique_ptr<CreditsMenuView> getCreditsMenuPresenter() = 0;
};

#endif //PRESENTER_FACTORY_HPP
