#ifndef __WRONGANIMAL__
# define __WRONGANIMAL__
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal& x);
		const std::string& getType(void) const;
		void setType(const std::string& copy);
		void makeSound(void) const;
	protected:
		std::string _type;

};

#endif