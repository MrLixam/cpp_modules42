#ifndef FIXED_HPP
# define FIXED_HPP

#include <fstream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed& src);
		int getRawBits(void);
		void setRawBits(int const raw);
		void operator=(Fixed& src);
		void operator<<(std::ofstream outfile);
		float toFloat(void);
		int toInt(void);
	private:
		int _value;
		static const int _fixed = 8;
};

#endif