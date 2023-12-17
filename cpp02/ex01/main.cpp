#include "Fixed.hpp"

#include <iostream>

int main(){
	Fixed a(256);

	std::cout << a.toFloat();
}