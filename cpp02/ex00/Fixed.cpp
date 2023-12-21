#include "Fixed.hpp"

Fixed::Fixed(){
	this->_value = 0;
}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed& src): _value(src._value){}

Fixed& Fixed::operator=(const Fixed& src){
	this->_value = src._value;
	return (*this);
}

int Fixed::getRawBits(void){
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}