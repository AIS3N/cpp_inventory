#include "Log.hh"

Log::Log()
{
  
}

Log::~Log()
{
  
}

std::vector<std::string> Log::getTrans() const
{
  return _trans;
}

void Log::clearTransactions()
{
  _trans.clear();
}

void	Log::addTrans(std::string str)
{
  _trans.push_back(str);
}

void	Log::overrightTxt()
{
  std::ofstream         file;

  file.open("./ressources/log.txt");
  std::ostream_iterator<std::string> out(file, "\n");
  std::copy(_trans.begin(), _trans.end(), out);
  file.close();
}

void   Log::fillTxt()
{
  std::ofstream         file;
  
  file.open("./ressources/log.txt", std::ofstream::app);
  std::ostream_iterator<std::string> out(file, "\n");
  std::copy(_trans.begin(), _trans.end(), out);
  file.close(); 
}
