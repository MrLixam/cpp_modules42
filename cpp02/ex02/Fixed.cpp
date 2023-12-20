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
	this->_value = src._value;
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(const Fixed& src){
	this->_value = src._value;
	return *this;
}

bool Fixed::operator>(const Fixed& cmp) const{
	return (this->_value > cmp._value);
}

bool Fixed::operator<(const Fixed& cmp) const{
	return (this->_value < cmp._value);
}

bool Fixed::operator>=(const Fixed& cmp) const{
	return (this->_value >= cmp._value);
}

bool Fixed::operator<=(const Fixed& cmp) const{
	return (this->_value <= cmp._value);
}

bool Fixed::operator==(const Fixed& cmp) const{
	return (this->_value == cmp._value);
}

bool Fixed::operator!=(const Fixed& cmp) const{
	return (this->_value != cmp._value);
}

Fixed Fixed::operator+(const Fixed& second) const{
	return Fixed(this->toFloat() + second.toFloat());
}

Fixed Fixed::operator-(const Fixed& second) const{
	return Fixed(this->toFloat() - second.toFloat());
}

Fixed Fixed::operator*(const Fixed& second) const{
	return Fixed(this->toFloat() * second.toFloat());
}

Fixed Fixed::operator/(const Fixed& second) const{
	return Fixed(this->toFloat() / second.toFloat());
}

Fixed& Fixed::operator++(void){
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed copy(*this);
	this->_value++;
	return (copy);
}

Fixed& Fixed::operator--(void){
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed copy(*this);
	this->_value--;
	return (copy);
}

int Fixed::toInt(void) const{
	return (this->_value / (1 << this->_fixed));
}

float Fixed::toFloat(void) const{
	return((float)this->_value / (1 << this->_fixed));
}

int Fixed::getRawBits(void) const{
	return (this->_value);
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a < b)
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a < b)
		return (b);
	return (a);
}

std::ostream& operator<<(std::ostream& outfile, const Fixed& val){
	outfile << val.toFloat();
	return (outfile);
}