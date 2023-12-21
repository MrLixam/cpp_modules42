#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void){
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
	}
	{
		const WrongAnimal *alone = new WrongAnimal();
		const WrongAnimal *as_cat = new WrongCat();
		std::cout << alone->getType() << " " << std::endl;
		std::cout << as_cat->getType() << " " << std::endl;
		alone->makeSound();
		as_cat->makeSound();
		delete as_cat;
		delete alone;
	}
}