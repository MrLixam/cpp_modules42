#include "randomClass.hpp"
#include <cstdlib>
#include <iostream>

Base::Base() { }

Base::~Base() { }

A::A() { }

A::~A() { }

B::B() { }

B::~B() { }

C::C() { }

C::~C() { }

Base * generate(void)
{
	int rand_num = rand() % 3;
	if (rand_num == 0)
	{
		std::cout << "The object type is:		A" << std::endl;
		return (new A);
	}
	else if (rand_num == 1)
	{
		std::cout << "The object type is:		B" << std::endl;
		return (new B);
	}
	else if (rand_num == 2)
	{
		std::cout << "The object type is:		C" << std::endl;
		return (new C);
	}
	else
	{
		std::cerr << "this shouldn't be possible, what.";
		exit(1);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The first detected type is:	A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "The first detected type is:	B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "The first detected type is:	C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A temp = dynamic_cast<A &>(p);
		std::cout << "The second detected type is:	A" << std::endl;
		return ;
	}
	catch ( ... ) {}
	try 
	{
		B temp = dynamic_cast<B &>(p);
		std::cout << "The second detected type is:	B" << std::endl;
		return ;
	}
	catch ( ... ) {}
	try
	{
		C temp = dynamic_cast<C &>(p);
		std::cout << "The second detected type is:	C" << std::endl;
		return ;
	}
	catch ( ... ) {}
}