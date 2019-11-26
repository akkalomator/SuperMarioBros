#ifndef MOVE_BACK_EXCEPTION_HPP
#define MOVE_BACK_EXCEPTION_HPP

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


#endif //MOVE_BACK_EXCEPTION_HPP
