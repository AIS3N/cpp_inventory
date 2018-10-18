#include "WeaponInventory.hh"
#include "Compte.hh"
#include "Transaction.hh"
#include "Exception.hh"
#include "Log.hh"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>

void	checkFile(const std::string& path)
{
  std::ifstream file(path);
  std::string	line;
  int		nbr;
  std::string	str;
  while (std::getline(file, line))
    {
      std::istringstream iss(line);
      iss >> str >> nbr;
      if (str != "SB" && str != "G" && str != "B" && str != "MG" )
	throw std::runtime_error("Accounting borked");
      if (nbr < 0)
	throw std::runtime_error("Accounting borked");
      std::cout << str << " : " << nbr << std::endl;
    }
  file.close();
}

void	transaction_list()
{
  std::string line;
  int		nbr;
  std::string	str;

  std::ifstream file("./ressources/log.txt");
  if (file.is_open())
    {
      while (std::getline(file, line))
	{
	  std::istringstream iss(line);
	  iss >> str >> nbr;
	  std::cout << "Transaction " << nbr <<  std::endl;
	}
      file.close();
    }
}

int	checkFaithfullness(std::string name)
{
  std::string	line;
  int		i;
  std::string	str;
  std::ifstream file("./ressources/log.txt");

  i = 0;
  if (file.is_open())
    {
      while (std::getline(file, line))
	{
	  std::stringstream iss(line);
	  iss >> str;
	  if (str == name)
	    i++;
	}
      if (i == 0)
	std::cout << "Bienvenue, " << name << std::endl;
    }
  return (i);
}

int	new_transaction(Transaction t, Compte compte, std::string to, WeaponInventory wp, Log log)
{
  std::string           str;
  std::string		log_str;
  int			price;
  std::cout << "Mode Nouvelle Transaction" << std::endl;
  while (str != "quit")
    {
      std::getline(std::cin, str);
      std::cout << to  << ">";
      if (str == "cancel")
	{
	  t.clearTransactions();
	  str ="quit";
	}
      else if (str == "commit")
	{
	  price = checkFaithfullness(to);
	  if (price > 20 && price < 100)
	    price = (t.getTotal() * 10) / 100;
	  else if (price > 100 && price < 500)
	    price = (t.getTotal() * 15) / 100;
	  else if (price > 500)
	    price = (t.getTotal() * 25) / 100;
	  else
	    price = t.getTotal();
	  log_str = to + " " + std::to_string(price) + " " + std::to_string(t.getPower()) + " " + std::to_string(t.getCount("StealthBox")) + " " + std::to_string(t.getCount("Gun")) + " " + std::to_string(t.getCount("Bomb")) + " " + std::to_string(t.getCount("MetalGear"));
	  log.addTrans(log_str);
	  log.fillTxt();
	  compte.fillTxt();
	  t.printSummary();
	  t.clearTransactions();
	  str = "quit";
	}
      else if (str == "total")
	std::cout << t.getTotal();
      else if (str == "power")
	std::cout << t.getPower();
      else if (str == "count")
	std::cout << t.getCount();
      else if (str == "count sb")
	std::cout << t.getCount("StealthBox");
      else if (str == "count g")
	std::cout << t.getCount("Gun");
      else if (str == "count b")
	std::cout << t.getCount("Bomb");
      else if (str == "count mg")
	std::cout << t.getCount("MetalGear");
      else if (str == "add sb")
	t.addWeapon(wp.sellStealthBox(compte));
      else if (str == "add g")
	t.addWeapon(wp.sellGun(compte));
      else if (str == "add b")
	t.addWeapon(wp.sellBomb(compte));
      else if (str == "add mg")
	t.addWeapon(wp.sellMetalGear(compte));
      else if (str == "summary")
	t.printSummary();
      else if (str == "to")
	std::cout << to;
    }
  return (0);
}

int main()
{
  std::ofstream		file;
  Compte		compte(1, 0, 1, 1);
  WeaponInventory	wp(1, 0, 1, 1);
  Transaction		t("Big Boss");
  std::string		line;
  std::string		str;
  std::string		to;
  Log			log;

  compte.fillTxt();
  try
    {
      checkFile("./ressources/compte.txt");
    }
  catch (std::exception const& e)
    {
      std::cerr << e.what() << std::endl;
    }
  while (str != "quit")
    {
      std::getline(std::cin, str);
      if (str == "transaction list")
	{
	  transaction_list();
        }
      else if(str == "transaction clear")
	{
	  log.clearTransactions();
	  log.overrightTxt();
	}
      else if (str == "transaction new")
	{
	  std::cin >> to;
	  new_transaction(t, compte, to, wp, log);
	}
    }
  return 0;
}
