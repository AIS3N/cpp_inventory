#include "Exception.hh"

Exception::Exception(std::string str) : _msg(str)
{
  
}

Exception::~Exception()
{
  
}

const char*	Exception::what() const noexcept
{
  return this->msg;
}
