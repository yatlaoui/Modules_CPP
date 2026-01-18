/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:52:18 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/26 11:27:03 by yaatlaou         ###   ########.fr       */
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

// ============================================================================
// COMPARISON OPERATORS (6 operators)
// ============================================================================

bool Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const 
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const 
{
	return this->_fixedPointValue != other._fixedPointValue;
}

// ============================================================================
// ARITHMETIC OPERATORS (4 operators)
// ============================================================================

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long temp = (long)this->_fixedPointValue * (long)other._fixedPointValue;
	result.setRawBits(temp >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long temp = ((long)this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	result.setRawBits(temp);
	return result;
}

// ============================================================================
// INCREMENT/DECREMENT OPERATORS (4 operators)
// ============================================================================

Fixed &Fixed::operator++() // Pre-increment: ++a (increments then returns)
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) // Post-increment: a++ (returns then increments)
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

// ============================================================================
// STATIC MIN/MAX FUNCTIONS
// ============================================================================

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
