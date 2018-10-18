#include "Compte.hh"

Compte::Compte(int sb, int g, int b, int mg) : _sb(sb), _g(g), _b(b), _mg(mg)
{
  
}

Compte::~Compte()
{
  
}

int	Compte::getSb() const
{
  return this->_sb;
}

int     Compte::getG() const
{
  return this->_g;
}

int     Compte::getB() const
{
  return this->_b;
}

int     Compte::getMg() const
{
  return this->_mg;
}

void	Compte::setSb(bool sell)
{
  if (sell)
    {
      if (this->_sb > 0)
	this->_sb = this->_sb - 1;
    }
  else
    this->_sb = this->_sb + 1;
}

void	Compte::setG(bool sell)
{
  if (sell)
    {
      if (this->_g > 0)
	this->_g = this->_g - 1;
    }
  else
    this->_g = this->_g + 1;
}

void	Compte::setB(bool sell)
{
  if (sell)
    {
      if (this->_b > 0)
	this->_b = this->_b - 1;
    }
  else
    this->_b = this->_b + 1;
}

void	Compte::setMg(bool sell)
{
  if (sell)
    {
      if (this->_mg > 0)
	this->_mg = this->_mg - 1;
    }
  else
    this->_mg = this->_mg + 1;
}


void   Compte::fillTxt()
{
  std::ofstream         file;

  file.open("./ressources/compte.txt");
  file << "SB " << this->_sb << "\nG " << this->_g << "\nB " << this->_b << "\nMG " << this->_mg;
  file.close(); 
}
