#include "WeaponInventory.hh"
#include "Weapon.hh"
#include "StealthBox.hh"
#include "Gun.hh"
#include "Bomb.hh"
#include "MetalGear.hh"

WeaponInventory::WeaponInventory(int nbStealthBox, int nbGun, int nbBomb, int nbMetalGear)
  : _nbStealthBox(nbStealthBox),
    _nbGun(nbGun),
    _nbBomb(nbBomb),
    _nbMetalGear(nbMetalGear) {
}

Weapon* WeaponInventory::sellStealthBox(Compte& compte)
{
  compte.setSb(true);
  compte.fillTxt();
  return makeWeapon(_nbStealthBox,[]() { return new StealthBox(); });
}

Weapon* WeaponInventory::sellGun(Compte& compte) {
  compte.setG(true);
  compte.fillTxt();
  return makeWeapon(
  	_nbGun,
  	[]() { return new Gun(); });
}

Weapon* WeaponInventory::sellBomb(Compte& compte) {
  compte.setB(true);
  compte.fillTxt();
  return makeWeapon(
  	_nbBomb,
  	[]() { return new Bomb(); });
}

Weapon* WeaponInventory::sellMetalGear(Compte& compte) {
  compte.setMg(true);
  compte.fillTxt();
  return makeWeapon(
  	_nbMetalGear,
  	[]() { return new MetalGear(); });
}

void WeaponInventory::buyStealthBox(Compte& compte) {
  compte.setSb(false);
  compte.fillTxt();
  _nbStealthBox++;
}

void WeaponInventory::buyGun(Compte& compte) {
  compte.setG(false);
  compte.fillTxt();
  _nbGun++;
}

void WeaponInventory::buyBomb(Compte& compte) {
  compte.setB(false);
  compte.fillTxt();
  _nbBomb++;
}

void WeaponInventory::buyMetalGear(Compte& compte) {
  compte.setMg(false);
  compte.fillTxt();
  _nbMetalGear++;
}

WeaponInventory::~WeaponInventory() {
  for (Weapon* weapon : _soldWeapons)
    delete weapon;
}

Weapon* WeaponInventory::makeWeapon(int& counter, std::function<Weapon*()> maker) {
  if (counter > 0) {
    --counter;
    return maker();
  }
  else
    std::cout << "Plus de stock !";
  return nullptr;
}
