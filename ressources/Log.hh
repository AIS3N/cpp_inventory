#ifndef __LOG_H__
#define __LOG_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

class Log
{
  std::vector<std::string> _trans;
public:
  Log();
  ~Log();
  std::vector<std::string> getTrans() const;
  void	clearTransactions();
  void addTrans(std::string);
  void fillTxt();
  void overrightTxt();
};

#endif
