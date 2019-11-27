// Platform class
// Mario can run or jump on it
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class GameObject {
public:
    GameObject();
    GameObject(int width, int height, bool isTouchable);
    ~GameObject();
    
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void draw(std::shared_ptr<sf::RenderWindow> window);
    void setTexture(std::string texturePath);
    sf::Texture getTexture();
    bool setTextureRepeat(bool repeat);

    bool isTouchable() const;
    int getLeftBorder() const;
    int getRightBorder() const;
    int getUpperBorder() const;
    int getLowerBorder() const;

protected:
    sf::IntRect rect_;
    sf::Texture texture_;
    sf::Sprite sprite_;
    bool textureRepeat_;
    bool isTouchable_;
};
