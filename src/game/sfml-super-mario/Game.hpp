#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameObjectManager.hpp"
#include "Player.hpp"
#include "Camera.hpp"

// Game class
// controls game events and object rendering
// all methods and properties are called statically
class Game {
public:
    
    static int width;
    static int height;
    static std::string title;
    
    // define various game states
    enum GameState {
        RUNNING,
        EXITING,
        UNINITIALIZED,
        PAUSE
    };
    
    static void run(std::shared_ptr<sf::RenderWindow> window);
    static GameObjectManager getManager();
    
private:
    
    static GameState gameState_;
    static std::shared_ptr<sf::RenderWindow> window_;
    static GameObjectManager gameObjectManager_;
    
    static void loop(Player& player);
    static bool isRunning();
    
    static sf::Clock timer_;
    static float deltaTime_;
    static Camera camera_;
};
