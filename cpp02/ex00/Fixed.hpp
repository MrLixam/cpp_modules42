#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& src);
		int getRawBits(void);
		void setRawBits(int const raw);
		Fixed& operator=(const Fixed& src);
	private:
		int _value;
		static const int _fixed = 8;
};

#endif