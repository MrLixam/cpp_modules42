#ifndef __ANIMAL__
# define __ANIMAL__
#include <string>
#include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(std::string type);
		Animal(Animal &copy);
		Animal& operator=(const Animal& x);
		const std::string& getType(void) const;
		void setType(const std::string& copy);
		virtual void makeSound(void) const;
		virtual Brain* getBrain(void) = 0;
	protected:
		std::string _type;

};

#endif