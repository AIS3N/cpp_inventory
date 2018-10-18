#include "Weapon.hh"

Weapon::Weapon(int price, int power)
  : _price{price},
    _power{power} {

}

Weapon::~Weapon()
{
  
}

int Weapon::getPrice() const {
	return _price;
}

int Weapon::getPower() const {
	return _power;
}
