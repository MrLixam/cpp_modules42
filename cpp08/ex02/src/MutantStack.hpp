#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack& copy);
		~MutantStack(void);
		MutantStack& operator=(const MutantStack& copy);
		typedef typename std::stack<T>::container_type Container;

		typedef typename Container::iterator iterator;
		iterator begin() { return (this->c.begin()); };
		iterator end() { return (this->c.end()); };

		typedef typename Container::const_iterator const_iterator;
		const_iterator cbegin() const { return (this->c.begin()); };
		const_iterator cend() const { return (this->c.end()); };

		typedef typename Container::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return (this->c.rbegin()); };
		reverse_iterator rend() { return (this->c.rend()); };

		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() const { return (this->c.rbegin()); };
		const_reverse_iterator crend() const { return (this->c.rend()); };
};

template<typename T>
MutantStack<T>::MutantStack(void) { }

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy)
{
	this->c = copy.c;
}

template<typename T>
MutantStack<T>::~MutantStack() { }

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy)
{
	if (this != &copy)
	{
		this->c = copy.c;
	}
	return (*this);
}

#endif