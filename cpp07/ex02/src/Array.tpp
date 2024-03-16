#include "Array.hpp"
#include <cstdlib>

template<typename T>
Array<T>::Array(void): _array(NULL), _size(0) { }


template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) { }

template<typename T>
Array<T>::Array(const Array<T>& copy): _array(new T[copy._size]), _size(copy._size)
{
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = copy._array[i];
	}
}

template<typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw Array<T>::OutOfBoundsException();
	return (_array[n]);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T>& copy)
{
	if (this != &copy)
	{
		delete [] (_array);
		_size = copy._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = copy._array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] (_array);
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}