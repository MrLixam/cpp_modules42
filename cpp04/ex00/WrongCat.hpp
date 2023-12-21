#ifndef __WRONGCAT__
# define __WRONGCAT__
#include "WrongAnimal.hpp"
#include <string>

class WrongCat: public WrongAnimal{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat &copy);
		WrongCat& operator=(const WrongCat& x);
		void makeSound(void) const;
};

#endif