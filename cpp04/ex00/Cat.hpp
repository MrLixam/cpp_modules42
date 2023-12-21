#ifndef __CAT__
# define __CAT__
#include "Animal.hpp"
#include <string>

class Cat: public Animal{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat &copy);
		Cat& operator=(const Cat& x);
		void makeSound(void) const;
};

#endif