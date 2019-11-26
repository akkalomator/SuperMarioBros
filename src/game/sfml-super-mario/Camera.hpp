#ifndef SUPERMARIOBROS3_CAMERA_HPP
#define SUPERMARIOBROS3_CAMERA_HPP


class Camera
{
public:
  void setX(float x);
  void setY(float y);

  float getX() const;
  float getY() const;

private:
  float x_;
  float y_;
};


#endif //SUPERMARIOBROS3_CAMERA_HPP
