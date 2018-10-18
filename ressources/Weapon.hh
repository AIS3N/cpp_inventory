#pragma once
#include <string>

class Weapon {
  int _price;
  int _power;

public:
  Weapon(int price, int power);
  virtual ~Weapon();
  int getPrice() const;
  int getPower() const;
  std::string const& getName() const;
};
