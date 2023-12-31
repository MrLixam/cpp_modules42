#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void): Animal("Cat"){
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(Cat &copy): Animal(copy.getType())
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain();
	this->_brain = copy._brain;
}

Cat& Cat::operator=(const Cat& x)
{
	std::cout << "Cat Operator Overload called" << std::endl;
	this->setType(x.getType());
	this->_brain = x._brain;
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << "Meeeeoww :)" << std::endl;
}

Brain* Cat::getBrain(void){
	return (this->_brain);
}