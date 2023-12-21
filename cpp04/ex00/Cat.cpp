#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal("Cat"){
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(Cat &copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->setType(copy.getType());
}

Cat& Cat::operator=(const Cat& x)
{
	std::cout << "Cat Operator Overload called" << std::endl;
	this->setType(x.getType());
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << "Meeeeoww :)" << std::endl;
}