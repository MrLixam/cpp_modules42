#ifndef __SCAVTRAP__
# define __SCAVTRAP__

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
		ScavTrap(void);
		~ScavTrap(void);
		ScavTrap(std::string name);
		void guardGate(void);
		void attack(const std::string& target);
	private:
		bool _guarding_gate;
};

#endif