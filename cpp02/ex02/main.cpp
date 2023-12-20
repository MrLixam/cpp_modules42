#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b( 1234.4321f );
	a = Fixed( 10 );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "--------------------" << std::endl;
	if (a < b)
		std::cout << "a is smaller than b" << std::endl;
	else
		std::cout << "a is not smaller than b" << std::endl;
	if (a > b)
		std::cout << "a is bigger than b" << std::endl;
	else
		std::cout << "a is not bigger than b" << std::endl;
	if (a == b)
		std::cout << "a is equal b" << std::endl;
	else
		std::cout << "a is not equal b" << std::endl;
	if (a <= b)
		std::cout << "a is smaller or equal b" << std::endl;
	else
		std::cout << "a is not smaller or equal b" << std::endl;
	if (a >= b)
		std::cout << "a is bigger or equal b" << std::endl;
	else
		std::cout << "a is not bigger or equal b" << std::endl;
	if (a != b)
		std::cout << "a is different than b" << std::endl;
	else
		std::cout << "a is not different than b" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "a (" << a << ") + b (" << b << ") = " << a + b << std::endl;
	std::cout << "a (" << a << ") - b (" << b << ") = " << a - b << std::endl;
	std::cout << "a (" << a << ") / b (" << b << ") = " << a / b << std::endl;
	std::cout << "a (" << a << ") * b (" << b << ") = " << a * b << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "MIN : a (" << a << ") & b (" << b << ") = " << Fixed::min(a,b) << std::endl;
	std::cout << "MAX : a (" << a << ") & b (" << b << ") = " << Fixed::max(a,b) << std::endl;
	std::cout << "CONST MIN : b (" << b << ") & a (" << a << ") = " << Fixed::min(b,a) << std::endl;
	std::cout << "CONST MAX : b (" << b << ") & a (" << a << ") = " << Fixed::max(b,a) << std::endl;
	std::cout << a * 0 << std::endl;
	std::cout << "a (" << a << ") / 0 (" << "0" << ") = " << a / 0 << std::endl;
	return 0;
}