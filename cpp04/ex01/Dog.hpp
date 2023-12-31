#ifndef __DOG__
# define __DOG__
#include <string>
#include "Brain.hpp"
#include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog &copy);
		Dog& operator=(const Dog& x);
		void makeSound(void) const;
		Brain* getBrain(void);
	private:
		Brain *_brain;
};

#endif