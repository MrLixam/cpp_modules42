#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

#define LOOKUP -2

#define LOOKUP_INVALID 12

int main(void)
{
	int base_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -2};

	std::vector<int> int_vector(base_array, base_array + 11);
	std::deque<int> int_deque(base_array, base_array + 11);
	std::list<int> int_list(base_array, base_array + 11);

	// Test for vector container
	std::vector<int>::iterator it_vec = easyfind(int_vector, LOOKUP);
	if (it_vec == int_vector.end())
		std::cout << LOOKUP << " is not in the vector" << std::endl;
	else
		std::cout << LOOKUP << " is in the vector at index: " << (it_vec - int_vector.begin()) << std::endl;
	it_vec = easyfind(int_vector, LOOKUP_INVALID);
	if (it_vec == int_vector.end())
		std::cout << LOOKUP_INVALID << " is not in the vector" << std::endl;
	else
		std::cout << LOOKUP_INVALID << " is in the vector at index: " << (it_vec - int_vector.begin()) << std::endl;

	// Test for deque container
	std::deque<int>::iterator it_deque = easyfind(int_deque, LOOKUP);
	if (it_deque == int_deque.end())
		std::cout << LOOKUP << " is not in the deque" << std::endl;
	else
		std::cout << LOOKUP << " is in the deque at index: " << (it_deque - int_deque.begin()) << std::endl;

	it_deque = easyfind(int_deque, LOOKUP_INVALID);
	if (it_deque == int_deque.end())
		std::cout << LOOKUP_INVALID << " is not in the deque" << std::endl;
	else
		std::cout << LOOKUP_INVALID << " is in the deque at index: " << (it_deque - int_deque.begin()) << std::endl;

	// Test for list container
	std::list<int>::iterator it_list = easyfind(int_list, LOOKUP);
	if (it_list == int_list.end())
		std::cout << LOOKUP << " is not in the list" << std::endl;
	else
		std::cout << LOOKUP << " is in the list at index: " << std::distance(int_list.begin(), it_list) << std::endl;

	it_list = easyfind(int_list, LOOKUP_INVALID);
	if (it_list == int_list.end())
		std::cout << LOOKUP_INVALID << " is not in the list" << std::endl;
	else
		std::cout << LOOKUP_INVALID << " is in the list at index: " << std::distance(int_list.begin(), it_list) << std::endl;
}