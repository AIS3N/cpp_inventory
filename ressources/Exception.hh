#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
#include <fstream>
#include <exception>

class Exception : public std::exception
{
  std::string	_msg;
public:
  Exception(std::string);
  virtual ~Exception();
  virtual const char* what() const  noexcept;
};

#endif
