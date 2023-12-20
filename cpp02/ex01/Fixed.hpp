#ifndef FIXED_HPP
# define FIXED_HPP

#include <fstream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed& operator=(const Fixed& src);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int _value;
		static const int _fixed = 8;
};

std::ostream& operator<<(std::ostream& outfile, const Fixed& val);

#endif