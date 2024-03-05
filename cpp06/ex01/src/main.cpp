#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

void printData(Data *ptr)
{
	std::cout << ptr->str << '\n';
	std::cout << ptr->number << '\n';
	std::cout << ptr->c << '\n';
	std::cout << ptr->flt << '\n';
	std::cout << ptr->dbl << '\n' << std::endl;
}

int main()
{
	Data data;
	data.str = "Hello";
	data.number = 42;
	data.c = 'c';
	data.flt = 42.42f;
	data.dbl = 42.42;

	printData(&data);
	uintptr_t serializedData = Serializer::serialize(&data);

	std::cout << serializedData << '\n' << std::endl;

	Data *deserializedData = Serializer::deserialize(serializedData);

	printData(deserializedData);
	return 0;
}