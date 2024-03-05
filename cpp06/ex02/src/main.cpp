#include "randomClass.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

/*
			|\    o
			|  \    o
		|\ /    .\ o
		| |       (     Le Fishe Au Chocolat *Le Frenshe Music*
		|/ \     /
			|  /
			|/
*/

int main()
{
	Base *LeFishe;
	srand(time(NULL) ^ getpid());
	for (int i = 0; i < 100; i++)
	{
		LeFishe = generate();
		identify(LeFishe);
		identify(*LeFishe);
		std::cout << std::endl;
		delete LeFishe;
	}
}