#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal("WrongCat"){
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &copy)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	this->setType(copy.getType());
}

WrongCat& WrongCat::operator=(const WrongCat& x)
{
	std::cout << "WrongCat Operator Overload called" << std::endl;
	this->setType(x.getType());
	return (*this);
}

void WrongCat::makeSound(void) const{
	std::cout << "Meeeeoww :)" << std::endl;
}
