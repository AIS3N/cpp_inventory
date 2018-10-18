#include "Transaction.hh"
#include <functional>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <numeric>

Transaction::Transaction(std::string to)
  : _to{std::move(to)} {
}


void Transaction::addWeapon(Weapon* obj) {
  if (obj) {
    _weapons.push_back(obj);
  }
}

void Transaction::clearTransactions()
{
  _transactions.clear();
}

void Transaction::addTransaction(Transaction* obj)
{
  _transactions.push_back(obj);
}

std::vector<Transaction*>	Transaction::getTransactions()
{
  return _transactions;
}

int Transaction::getTotal() {
  return std::accumulate(_weapons.begin(), _weapons.end(), 0, [](int memo, Weapon* w) {
    return memo + w->getPrice();
  });
}

int Transaction::getPower() {
  return std::accumulate(_weapons.begin(), _weapons.end(), 0, [](int memo, Weapon* w) {
    return memo + w->getPower();
  });
}

int Transaction::getCount() {
  return _weapons.size();
}

int Transaction::getCount(std::string name) {
  return std::count_if(_weapons.begin(), _weapons.end(), [&name](Weapon *obj) {
      if (name == "StealthBox" && dynamic_cast<StealthBox*>(obj))
	return true;
      else if (name == "Gun" && dynamic_cast<Gun*>(obj))
	return true;
      else if (name == "Bomb" && dynamic_cast<Bomb*>(obj))
	return true;
      else if (name == "MetalGear" && dynamic_cast<MetalGear*>(obj))
	return true;
      return false;
  });
}

void Transaction::printSummary() {
  std::cout << "Transaction de vers " << _to << "Nombre d'armes : " << getCount() << "\n";
  std::cout << "Détails : \n";
  for (std::string const& type : {"StealthBox", "Gun", "Bomb", "MetalGear"}) {
    std::cout << "  - " << getCount(type) << " de " << type << "\n";
  }
  std::cout << "Prix : " << getTotal() << ". Puissance : " << getPower() << "." << std::endl;
}
