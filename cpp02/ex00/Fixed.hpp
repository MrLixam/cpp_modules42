#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed& src);
		int getRawBits(void);
		void setRawBits(int const raw);
		void operator=(Fixed& src);
	private:
		int value;
		static const int fixed = 8;
};

#endif