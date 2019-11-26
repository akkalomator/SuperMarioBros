#include "GameObject.hpp"
#include "../../resource-loader/SfmlResourceLoader.hpp"

GameObject::GameObject() : rect_(0, 0, 0, 0), textureRepeat_(true)
{
  this->sprite_.setPosition(0, 0);
}

GameObject::GameObject(int width, int height, bool isTouchable) :
    rect_(0, 0, width, height),
    textureRepeat_(true),
    isTouchable_(isTouchable)
{
  this->sprite_.setPosition(0, 0);
}

GameObject::~GameObject()
{}

void GameObject::setPosition(float x, float y)
{
  this->sprite_.setPosition(x, y);
}

sf::Vector2f GameObject::getPosition()
{
  return this->sprite_.getPosition();
}

void GameObject::draw(std::shared_ptr<sf::RenderWindow> window)
{
  window->draw(this->sprite_);
}

void GameObject::setTexture(std::string texturePath)
{
  this->texture_ = *SfmlResourceLoader::getTexture(texturePath);
  this->texture_.setRepeated(this->textureRepeat_);
  this->sprite_.setTexture(this->texture_);
  this->sprite_.setTextureRect(this->rect_);
}

sf::Texture GameObject::getTexture()
{
  return this->texture_;
}

bool GameObject::setTextureRepeat(bool repeat)
{
  this->textureRepeat_ = repeat;
}

int GameObject::getLeftBorder() const
{
  return sprite_.getGlobalBounds().left;
}

int GameObject::getRightBorder() const
{
  const sf::FloatRect &bounds = sprite_.getGlobalBounds();
  return bounds.left + bounds.width;
}

int GameObject::getUpperBorder() const
{
  return sprite_.getPosition().y;
}

int GameObject::getLowerBorder() const
{
  return sprite_.getPosition().y + sprite_.getTextureRect().height;
}

bool GameObject::isTouchable() const
{
  return isTouchable_;
}
