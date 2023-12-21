#include "ClapTrap.hpp"

int main(void){
	ClapTrap test1;
	ClapTrap test2("INAC");
	ClapTrap test3("INVALID");
	ClapTrap test4(test2);
	ClapTrap test5("SH4D0W-TP");

	test3 = test1;
	test1.attack("Test Dummy");
	test2.attack("Test Dummy");
	test3.attack("Lord Test Dummy the 2nd");
	test4.attack("Lord Test Dummy the 2nd");
	test1.takeDamage(9);
	test2.takeDamage(10);
	test2.attack("Test Dummy");
	test4.beRepaired(50);
	test3.beRepaired(100);
	test1.takeDamage(10);
	test2.takeDamage(1);
	for (int i = 0; i <= 15; i++){
		test5.beRepaired(1);
	}
	test5.takeDamage(10);
	return 0;
}