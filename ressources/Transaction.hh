#pragma once
#include <string>
#include <vector>
#include "Weapon.hh"
#include "StealthBox.hh"
#include "Gun.hh"
#include "Bomb.hh"
#include "MetalGear.hh"

class Transaction {
  std::string			_to;
  std::vector<Weapon*>		_weapons;
  std::vector<Transaction*>	_transactions;

public:
  Transaction(std::string to);
  void addTransaction(Transaction* obj);
  void addWeapon(Weapon* obj);
  std::vector<Transaction*> getTransactions();
  void clearTransactions();
  int getTotal();
  int getPower();
  int getCount();
  int getCount(std::string);  
  void printSummary();
};
