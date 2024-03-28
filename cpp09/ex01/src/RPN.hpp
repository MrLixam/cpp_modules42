#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class Rpn
{
	private:
		std::stack<std::string> _stack;
		Rpn(const Rpn& copy);
		Rpn(void);
		long long add(long long value1, long long value2);
		long long substract(long long value1, long long value2);
		long long multiply(long long value1, long long value2);
		long long divide(long long value1, long long value2);
	public:
		Rpn(std::string arguments);
		~Rpn(void);
		Rpn& operator=(const Rpn& copy);
};


#endif