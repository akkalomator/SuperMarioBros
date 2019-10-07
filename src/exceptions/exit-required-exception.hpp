#ifndef EXITREQUIREDEXCEPTION_HPP
#define EXITREQUIREDEXCEPTION_HPP

#include <exception>
#include <string>

class ExitRequiredException : public std::exception
{
public:
  ExitRequiredException() = default;
  explicit ExitRequiredException(std::string &msg);

  const char *what() const noexcept override;

private:
  std::string msg_;
};


#endif //EXITREQUIREDEXCEPTION_HPP
