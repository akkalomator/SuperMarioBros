#include "GameState.hpp"
#include "../../../game/sfml-super-mario/Game.hpp"
#include "../../../sfml-provider/SfmlProvider.hpp"

GameState::GameState(std::shared_ptr<StateMachine> &machine) :
    State(machine)
{
}

void GameState::onStart()
{
  // set background for game
  GameObject background(Game::width, Game::height, false);
  background.setTexture("../resources/images/background.png");
  GameObjectManager::add("background", background);

  // create ground
  GameObject platform(Game::width, 16, true);
  platform.setPosition(0, Game::height / 3 * 2);
  platform.setTexture("../resources/images/stage.png");
  GameObjectManager::add("platform", platform); // add to manager
  GameObject ground(Game::width, Game::height / 3 * 2 - 16, false);
  ground.setPosition(0, Game::height / 3 * 2 + 16);
  ground.setTexture("../resources/images/ground.png");
  GameObjectManager::add("ground", ground); // add to manager


  GameObject platform2(Game::width, 16, true);
  platform.setPosition(0, Game::height / 3 * 2 - 120);
  platform.setTexture("../resources/images/stage.png");
//  GameObjectManager::add("platform2", platform); // add to manager

  // run game
  Game::run(SfmlProvider::getWindow());
}

void GameState::update()
{}

void GameState::onStop()
{}
