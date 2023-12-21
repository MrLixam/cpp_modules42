#include "Zombie.hpp"

int main(void)
{
	Zombie* zombie1 = newZombie("Bob");
	Zombie* zombie2 = newZombie("Alice");

	randomChump("John");
	zombie1->announce();
	zombie2->announce();
	delete zombie1;
	delete zombie2;
	return (0);
}
