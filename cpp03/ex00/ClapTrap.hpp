#ifndef __CLAPTRAP__
# define __CLAPTRAP__

#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap& x);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string _name;
		unsigned int _hit_points;
		unsigned int _energy_points;
		unsigned int _attack_damage;
};

#endif