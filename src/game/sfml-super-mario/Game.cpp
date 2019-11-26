#include "Game.hpp"
#include "../../exceptions/ExitReqiredException.hpp"
#include "../../exceptions/MoveBackException.hpp"
#include "../../sfml-provider/SfmlProvider.hpp"
#include "Camera.hpp"

void Game::run(std::shared_ptr<sf::RenderWindow> window) {

  window_ = window;
  gameState_ = RUNNING;

  deltaTime_ = 0.0f;
  camera_.setX(0);
  camera_.setY(0);

  sf::Texture playerTexture;
  playerTexture.loadFromFile("../resources/images/supermario.png");
  Player player(&playerTexture, sf::Vector2u(3, 2), 1.0f, 10.0f, 75);
  player.setPosition(0, (float) height / 3 * 2 - playerTexture.getSize().y, camera_);

    while (isRunning()) {
      loop(player);
    }
}

void Game::loop(Player& player) {

  deltaTime_ = timer_.restart().asSeconds() * 25;

    // player current position
    sf::Vector2f pos = player.getPosition();

    sf::Event e;

    // waiting for user action
    while (window_->pollEvent(e)) {
        if (e.type == sf::Event::EventType::Closed) {
          throw ExitRequiredException();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
          throw MoveBackException();
        }
    }

    window_->clear();

    // handling objects from object manager
    for(auto& platform : GameObjectManager::getObjects()) {
        platform.second.draw(window_);
    }

    player.update(deltaTime_, camera_);
    player.draw(window_);

    window_->display();
}

bool Game::isRunning() {
  return gameState_ != EXITING;

}

GameObjectManager Game::getManager() {
    return gameObjectManager_;
}

Game::GameState Game::gameState_ = UNINITIALIZED;
std::shared_ptr<sf::RenderWindow> Game::window_;

// set default values
int Game::width = SfmlProvider::WIDTH;
int Game::height = SfmlProvider::HEIGHT;
sf::Clock Game::timer_;
float Game::deltaTime_;
Camera Game::camera_;

