#ifndef SFMLPRESENTERFACTORY_HPP
#define SFMLPRESENTERFACTORY_HPP

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "presenter-factory.hpp"

class SfmlPresenterFactory : public PresenterFactory
{
public:
  explicit SfmlPresenterFactory(std::shared_ptr<sf::RenderWindow> &window);

  std::unique_ptr<MainMenuPresenter> getMainMenuPresenter() override ;

  std::unique_ptr<AboutMenuPresenter> getAboutMenuPresenter() override ;

  std::unique_ptr<CreditsMenuPresenter> getCreditsMenuPresenter() override ;

private:
  std::shared_ptr<sf::RenderWindow> window_;
};


#endif //SFMLPRESENTERFACTORY_HPP
