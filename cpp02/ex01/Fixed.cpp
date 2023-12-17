#include "Fixed.hpp"
#include <iostream>
#include <cstdlib>

Fixed::Fixed(){
	this->_value = 0;
}

Fixed::Fixed(const int value){
	this->_value = value * (2^(this->_fixed));
}

Fixed::~Fixed(){}

void Fixed::operator=(Fixed& src){
	this->_value = src.getRawBits();
}

void Fixed::operator<<(std::ofstream outfile){
	outfile << "placeholder" << std::endl;
}

int Fixed::toInt(void){ return (0);}

float Fixed::toFloat(void){
	int buffer = abs(this->_value);
	int sign = 1;
	if (this->_value < 0){
		buffer = this->_value - 1;
		buffer = ~buffer;
		sign = -1;
	}
	return(((1.0 * buffer) / (2 ^ this->_fixed)) * sign);
}

int Fixed::getRawBits(void){
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}