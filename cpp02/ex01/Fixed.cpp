#include "Fixed.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

Fixed::Fixed(){
	this->_value = 0;
}

Fixed::Fixed(const int value){
	this->_value = value * (1 << this->_fixed);
}

Fixed::Fixed(const float value){
	this->_value = (int)roundf(value *(1 << this->_fixed));
}

Fixed::Fixed(const Fixed& src){
	this->_value = src.getRawBits();
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& src){
	this->_value = src.getRawBits();
	return *this;
}

int Fixed::toInt(void) const{
	return (this->_value / (1 << this->_fixed));
}

float Fixed::toFloat(void) const{
	return((float)this->_value / (1 << this->_fixed));
}

int Fixed::getRawBits(void) const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

std::ostream& operator<<(std::ostream& outfile, const Fixed& val){
	outfile << val.toFloat();
	return (outfile);
}