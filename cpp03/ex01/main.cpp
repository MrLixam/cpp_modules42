#include "ScavTrap.hpp"

int main(void){
	{
		ScavTrap test1;
		ScavTrap test2("INAS");
		ScavTrap test3("INVALID");
		ScavTrap test4(test2);
		ScavTrap test5("SUP3R-SV-TP");

		test3 = test1;
		test1.attack("Test Dummy");
		test2.attack("Test Dummy");
		test3.attack("Lord Test Dummy the 2nd");
		test4.attack("Lord Test Dummy the 2nd");
		test1.takeDamage(9);
		test2.takeDamage(100);
		test2.attack("Test Dummy");
		test4.beRepaired(50);
		test3.beRepaired(100);
		test1.takeDamage(10);
		test2.takeDamage(1);
		for (int i = 0; i < 49; i++){
			test5.beRepaired(1);
		}
		test5.takeDamage(10);
		test5.ClapTrap::attack("ClapTrap's Dummy");
		test1.guardGate();
		test1.guardGate();
		test2.guardGate();
		test2.guardGate();
		test3.guardGate();
		test3.guardGate();
		test4.guardGate();
		test4.guardGate();
		test5.guardGate();
		test5.guardGate();
		return 0;
	}
}