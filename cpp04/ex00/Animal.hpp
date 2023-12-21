#ifndef __ANIMAL__
# define __ANIMAL__
#include <string>

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
	protected:
		std::string _type;

};

#endif