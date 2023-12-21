#include "FragTrap.hpp"

int main(void){
	{
		FragTrap test1;
		FragTrap test2("INAS");
		FragTrap test3("INVALID");
		FragTrap test4(test2);
		FragTrap test5("SUP3R-FG-TP");

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
		test1.highFive();
		test1.highFive();
		test2.highFive();
		test2.highFive();
		test3.highFive();
		test3.highFive();
		test4.highFive();
		test4.highFive();
		test5.highFive();
		test5.highFive();
		return 0;
	}
}