#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main(){
	Zombie *horde;

	horde = zombieHorde(10, "Bob");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	std::cout << std::endl;
	horde[5].setName("John");
	horde[9].setName("Alice");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	return (0);

}