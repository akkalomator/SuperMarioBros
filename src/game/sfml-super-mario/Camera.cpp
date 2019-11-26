//
// Created by mi2 on 25.11.2019.
//

#include "Camera.hpp"

void Camera::setX(float x)
{
  x_ = x;
}

void Camera::setY(float y)
{
  y_ = y;
}

float Camera::getX() const
{
  return x_;
}

float Camera::getY() const
{
  return y_;
}
