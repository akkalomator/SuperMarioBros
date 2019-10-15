#include "ExitReqiredException.hpp"

ExitRequiredException::ExitRequiredException(std::string &msg) :
    msg_(msg)
{
}

const char *ExitRequiredException::what() const noexcept
{
  return ("ExitRequiredException " + msg_).c_str();
}
