#include "Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal("Dog"){
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(Dog &copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->setType(copy.getType());
}

Dog& Dog::operator=(const Dog& x)
{
	std::cout << "Dog Operator Overload called" << std::endl;
	this->setType(x.getType());
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << "Bark bark!" << std::endl;
}