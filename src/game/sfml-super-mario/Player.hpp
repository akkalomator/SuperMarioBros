// Player class
// defines player animations and behavior
#pragma once

#include <memory>
#include "Animation.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"

class Player
{
public:
  Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);

  ~Player();

  void update(float deltaTime, Camera camera);

  void draw(std::shared_ptr<sf::RenderWindow> window);

  void setPosition(double x, double y, Camera camera);

  sf::Vector2f getPosition();

private:
  sf::RectangleShape body_;
  Animation animation_;
  unsigned int row_;
  float speed_;
  float speedMultiply_;
  bool faceRight_;

  sf::Vector2f velocity;
  float jumpHeight_;
  bool canJump_;
  bool isJumping_;

  void moveLeft();

  void moveRight();

  void jump();

  void fly(float deltaTime);

  bool isOnGround(const sf::Vector2f &pos) const;

  bool touches(int bounds, int y1, int upper, int lower) const;
};
