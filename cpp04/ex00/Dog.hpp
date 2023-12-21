#ifndef __DOG__
# define __DOG__
#include <string>
#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog &copy);
		Dog& operator=(const Dog& x);
		void makeSound(void) const;
};

#endif