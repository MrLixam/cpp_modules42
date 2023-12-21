#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{

}

ClapTrap::~ClapTrap(void)
{

}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& x)
{
	return (*this);
}
