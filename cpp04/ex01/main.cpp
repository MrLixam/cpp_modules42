#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define NBR_ANIMALS 10

int main(){
	Animal* lst[NBR_ANIMALS];

	for (int i = 0; i < NBR_ANIMALS; i++)
	{
		if (i % 2 == 1) {
			Animal *tmp = new Cat();
			lst[i] = tmp; 
		}
		else {
			Animal* tmp = new Dog();
			lst[i] = tmp;
		}
	}
	std::cout << "end of list creation" << std::endl;
	for (int i = 0; i < NBR_ANIMALS; i++){
		delete lst[i];
	}
	Dog test1;
	Dog test2(test1);
	Brain *brain1 = test1.getBrain();
	Brain *brain2 = test2.getBrain();

	brain1->setIdea(10, "this is base brain");
	brain2->setIdea(10, "this is copy brain");
	return (0);
}