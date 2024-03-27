#ifndef ARRAY_HPP
# define ARRAY_HPP

#define SIZE	10
#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"

#include <exception> 

template<typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(const Array &copy);
		Array& operator=(const Array& x);
		T& operator[](unsigned int n);
		unsigned int size(void) const;
		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Index out of bounds");
				}
		};
};

#endif