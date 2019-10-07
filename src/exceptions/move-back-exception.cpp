#include "move-back-exception.hpp"

MoveBackException::MoveBackException(std::string &msg) :
    msg_(msg)
    {}

const char *MoveBackException::what() const noexcept
{
  return ("MoveBackException " + msg_).c_str();
}
