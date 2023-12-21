#ifndef __CLAPTRAP__
# define __CLAPTRAP__

class ClapTrap
{
	public:
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap& x);
	private:

};

#endif