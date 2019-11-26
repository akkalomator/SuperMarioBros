#include "Player.hpp"
#include "../../sfml-provider/SfmlProvider.hpp"
#include "GameObjectManager.hpp"
#include <math.h>
#include <iostream>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation_(texture, imageCount, switchTime),
    speed_(speed),
    row_(0),
    faceRight_(true),
    jumpHeight_(jumpHeight),
    canJump_(true),
    isJumping_(false),
    speedMultiply_(1.5)
{
  this->body_.setSize(sf::Vector2f(16, 29));
  this->body_.setTexture(texture);
}

Player::~Player()
{}

void Player::setPosition(double x, double y, Camera camera)
{
//  this->body_.setPosition(x - camera.getX(), y - camera.getY() - body_.getGlobalBounds().height);
  this->body_.setPosition(x - camera.getX(), y - camera.getY() + body_.getGlobalBounds().height);
}

sf::Vector2f Player::getPosition()
{
  this->body_.getPosition();
}

void Player::update(float deltaTime, Camera camera)
{
  this->velocity.x = 0.0f;
  sf::Vector2f pos = this->body_.getPosition();

  // check if animation_ should startGame
  bool animate = false;

  // move left
  if (pos.x >= 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    animate = true;
    moveLeft();
  }

  // move right
  if (pos.x <= SfmlProvider::WIDTH - body_.getGlobalBounds().width && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    animate = true;
    moveRight();
  }

  // jump
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->canJump_)
  {
    this->canJump_ = false;
    this->isJumping_ = true;
    jump();
  }

  if (this->isJumping_)
  {
    animate = false;
    fly(deltaTime);
  }

  if (isOnGround(pos))
  {
    this->canJump_ = true;
    this->isJumping_ = false;
    this->velocity.y = 0.0f;
    for (const auto &obj : GameObjectManager::getObjects())
    {
      if (obj.second.isTouchable() &&
          touches(body_.getGlobalBounds().height, pos.y, obj.second.getUpperBorder(), obj.second.getLowerBorder()))
      {
        pos.y = obj.second.getUpperBorder();
        break;
      }
    }
    setPosition(pos.x, pos.y - body_.getGlobalBounds().height - body_.getGlobalBounds().height, camera);
  }


  if (this->velocity.x == 0.0f)
  {

    this->row_ = 0;
  } else
  {
    this->row_ = 0;

    this->faceRight_ = this->velocity.x > 0.0f;
  }

  bool defaultV = !animate;
  bool jump = false;

  if (this->isJumping_)
  {
    defaultV = false;
    jump = true;
  }

  this->animation_.update(row_, deltaTime, faceRight_, jump, defaultV);

  this->body_.setTextureRect(animation_.uvrect);
  if (pos.x > SfmlProvider::WIDTH * 2 / 3)
  {
    camera.setX(camera.getX() + velocity.x * deltaTime);
  }
  if (pos.y > SfmlProvider::HEIGHT * 2 / 3)
  {
    camera.setY(camera.getY() + velocity.y * deltaTime);
  }
//  setPosition(pos.x + velocity.x * deltaTime, pos.y - velocity.y * deltaTime, camera);
  this->body_.move(velocity * deltaTime);
}

bool Player::isOnGround(const sf::Vector2f &pos) const
{
  for (const auto &obj : GameObjectManager::getObjects())
  {
    if (obj.second.isTouchable() &&
        touches(body_.getGlobalBounds().height, pos.y, obj.second.getUpperBorder(), obj.second.getLowerBorder()))
    {
      return true;
    }
  }
  return false;
}

bool Player::touches(int bounds, int y1, int upper, int lower) const
{
  return y1 + bounds > upper && y1 < lower;
}

void Player::fly(float deltaTime)
{ velocity.y += 981.0f * deltaTime / 150; }

void Player::jump()
{ velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight_ / 150); }

void Player::moveRight()
{
  float tmpSpeed = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? speed_ * speedMultiply_ : speed_;
  velocity.x += tmpSpeed;
}

void Player::moveLeft()
{
  float tmpSpeed = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? speed_ * speedMultiply_ : speed_;
  velocity.x -= tmpSpeed;
}

void Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
  window->draw(this->body_);
}
