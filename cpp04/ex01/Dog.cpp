#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void): Animal("Dog"){
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_brain = new Brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(Dog &copy): Animal("Dog")
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_brain = new Brain;
	this->_brain = copy._brain;
}

Dog& Dog::operator=(const Dog& x)
{
	std::cout << "Dog Operator Overload called" << std::endl;
	this->setType(x.getType());
	this->_brain = x._brain;
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << "Bark bark!" << std::endl;
}

Brain* Dog::getBrain(void){
	return (this->_brain);
}