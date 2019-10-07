#ifndef SFMLABOUTMENUPRESENTER_HPP
#define SFMLABOUTMENUPRESENTER_HPP

#include <memory>
#include "about-menu-presenter.hpp"

class SfmlAboutMenuPresenter : public AboutMenuPresenter
{
public:
  explicit SfmlAboutMenuPresenter(std::shared_ptr<sf::RenderWindow> &window);

  void drawWindow() const override;

  void awaitExit() const override;

private:
  std::shared_ptr<sf::RenderWindow> window_;
};


#endif //SFMLABOUTMENUPRESENTER_HPP
