/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:52:18 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 23:45:47 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) 
{
}

Fixed::Fixed(const int value)
{
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy) 
		this->_fixedPointValue = copy.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &copy) const
{
	return this->_fixedPointValue > copy._fixedPointValue;
}

bool Fixed::operator<(const Fixed &copy) const
{
	return this->_fixedPointValue < copy._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &copy) const {
	return this->_fixedPointValue >= copy._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return this->_fixedPointValue <= copy._fixedPointValue;
}

bool Fixed::operator==(const Fixed &copy) const 
{
	return this->_fixedPointValue == copy._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &copy) const 
{
	return this->_fixedPointValue != copy._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + copy._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - copy._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	Fixed result;
	long temp = (long)this->_fixedPointValue * (long)copy._fixedPointValue;
	result.setRawBits(temp >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	Fixed result;
	long temp = ((long)this->_fixedPointValue << _fractionalBits) / copy._fixedPointValue;
	result.setRawBits(temp);
	return result;
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
