#include "Zombie.hpp"

void randomChump(std::string name);

Zombie* newZombie(std::string name);

int main(void)
{
	Zombie* zombie1 = newZombie("Bob");
	Zombie* zombie2 = newZombie("Alice");

	zombie1->announce();
	zombie2->announce();
	randomChump("John");
	delete zombie1;
	delete zombie2;
	return (0);
}
