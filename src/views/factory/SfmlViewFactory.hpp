#ifndef SFML_PRESENTER_FACTORY_HPP
#define SFML_PRESENTER_FACTORY_HPP

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "ViewFactory.hpp"

class SfmlViewFactory : public ViewFactory
{
public:
  explicit SfmlViewFactory(std::shared_ptr<sf::RenderWindow> &window);

  std::unique_ptr<MainMenuView> getMainMenuPresenter() override;

  std::unique_ptr<AboutMenuView> getAboutMenuPresenter() override;

  std::unique_ptr<CreditsMenuView> getCreditsMenuPresenter() override;

private:
  std::shared_ptr<sf::RenderWindow> window_;
};


#endif //SFML_PRESENTER_FACTORY_HPP
