#ifndef MOVEBACKEXCEPTION_HPP
#define MOVEBACKEXCEPTION_HPP

#include <exception>
#include <string>

class MoveBackException : public std::exception
{
public:
  MoveBackException() = default;
  explicit MoveBackException(std::string &msg);

  const char *what() const noexcept override;

private:
  std::string msg_;
};


#endif //MOVEBACKEXCEPTION_HPP
