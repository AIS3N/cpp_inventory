#ifndef __COMPTE_H__
#define __COMPTE_H__

#include <iostream>
#include <fstream>

class Compte
{
  int	_sb;
  int	_g;
  int	_b;
  int	_mg;
public:
  Compte(int, int, int, int);
  ~Compte();
  int	getSb() const;
  int	getG() const;
  int	getB() const;
  int	getMg() const;
  void	setSb(bool);
  void	setG(bool);
  void	setB(bool);
  void	setMg(bool);
  void	fillTxt();
};

#endif
