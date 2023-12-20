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
		Fixed& operator=(const Fixed& src);
		bool operator>(const Fixed& cmp) const;
		bool operator<(const Fixed& cmp) const;
		bool operator>=(const Fixed& cmp) const;
		bool operator<=(const Fixed& cmp) const;
		bool operator==(const Fixed& cmp) const;
		bool operator!=(const Fixed& cmp) const;
		Fixed operator+(const Fixed& second) const;
		Fixed operator-(const Fixed& second) const;
		Fixed operator*(const Fixed& second) const;
		Fixed operator/(const Fixed& second) const;
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);	
	private:
		int _value;
		static const int _fixed = 8;
};

std::ostream& operator<<(std::ostream& outfile, const Fixed& val);

#endif