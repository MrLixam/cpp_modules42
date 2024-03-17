#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, const int to_find)
{
	return (find(container.begin(), container.end(), to_find));
}

#endif