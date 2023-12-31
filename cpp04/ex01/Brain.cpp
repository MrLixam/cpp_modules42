#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain &copy)
{
	for (int i = 0; i < 100; i++){
		this->ideas[i] = copy.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& x)
{
	for (int i = 0; i < 100; i++){
		this->ideas[i] = x.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(size_t n, std::string idea){
	if (n >= 100){
		std::cout << "cannot put idea at this index" << std::endl;
		return ;
	}
	this->ideas[n] = idea;
}

void Brain::showIdeas(void) const{
	for (int i = 0; i < 100; i++){
		std::cout << ideas[i] << std::endl;
	}
}