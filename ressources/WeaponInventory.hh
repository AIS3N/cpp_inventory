#pragma once
#include <vector>
#include <functional>
#include <fstream>
#include "Compte.hh"

struct Weapon;
struct StealthBox;
struct Gun;
struct Bomb;
struct MetalGear;


class WeaponInventory {
  int _nbStealthBox, _nbGun, _nbBomb, _nbMetalGear;
  std::vector<Weapon*> _soldWeapons;

public:
  WeaponInventory(int nbStealthBox, int nbGun, int nbBomb, int nbMetalGear);
  Weapon* sellStealthBox(Compte&);
  Weapon* sellGun(Compte&);
  Weapon* sellBomb(Compte&);
  Weapon* sellMetalGear(Compte&);

  void buyStealthBox(Compte&);
  void buyGun(Compte&);
  void buyBomb(Compte&);
  void buyMetalGear(Compte&);

  ~WeaponInventory();
  
private:
  Weapon* makeWeapon(int& counter, std::function<Weapon*()> maker);
};
