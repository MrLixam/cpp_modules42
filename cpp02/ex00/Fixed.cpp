#include "Fixed.hpp"

Fixed::Fixed(){
	this->value = 0;
}

Fixed::~Fixed(){}

void Fixed::operator=(Fixed& src){
	this->value = src.getRawBits();
}

int Fixed::getRawBits(void){
	return (this->value);
}

void Fixed::setRawBits(int const raw){
	this->value = raw;
}