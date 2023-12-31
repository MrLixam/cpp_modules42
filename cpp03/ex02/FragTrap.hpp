#ifndef __FRAGTRAP__
# define __FRAGTRAP__

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(std::string name);
		void highFiveGuys(void) const;
};

#endif