/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:35:03 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/26 07:39:50 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// value << _fractionalBits = value << 8 = value * 256
// On multiplie par 256 pour "encoder" le nombre en fixed-point
// Exemple :
// Fixed a(10);
// // Internement : 10 << 8 = 10 * 256 = 2560
// Pourquoi << au lieu de * ?
// Plus rapide (une seule opération CPU au lieu d'une multiplication)
// Plus précis (pas d'arrondi)
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

// (1 << _fractionalBits) = (1 << 8) = 256
// value * 256 = conversion en fixed-point
// roundf(...) = arrondir au plus proche (pour minimiser l'erreur)
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixedPointValue = copy.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// (1 << 8) = 256
// Division pour "décoder" la valeur
float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits); //division par 256 pour decoder la valeur
}

// >> 8 = division par 256
// Automatiquement tronqué (partie décimale supprimée)
int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}


// le compilateur ne sait rien de Fixed.
// Il cherche donc une fonction qui ressemble à:
// std::ostream& operator<<(std::ostream&, Fixed);
// Si elle existe, bingo.
// Sinon, erreur de compilation.
// 👉 En surchargeant operator<<, tu enseignes au compilateur comment transformer ton objet en texte.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
