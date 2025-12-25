/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:52:13 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/24 15:45:42 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        // Constructors and destructor
        Fixed();                              // Default constructor
        Fixed(const int value);               // Int constructor
        Fixed(const float value);             // Float constructor
        Fixed(const Fixed &copy);            // Copy constructor
        ~Fixed();                             // Destructor

        // Assignment operator
        Fixed &operator=(const Fixed &copy);

        // Comparison operators (6 operators)
        // These allow us to compare two Fixed numbers
        bool operator>(const Fixed &copy) const;   // Greater than
        bool operator<(const Fixed &copy) const;   // Less than
        bool operator>=(const Fixed &copy) const;  // Greater than or equal
        bool operator<=(const Fixed &copy) const;  // Less than or equal
        bool operator==(const Fixed &copy) const;  // Equal to
        bool operator!=(const Fixed &copy) const;  // Not equal to

        // Arithmetic operators (4 operators)
        // These allow us to do math with Fixed numbers
        Fixed operator+(const Fixed &copy) const;  // Addition
        Fixed operator-(const Fixed &copy) const;  // Subtraction
        Fixed operator*(const Fixed &copy) const;  // Multiplication
        Fixed operator/(const Fixed &copy) const;  // Division

        // Increment/Decrement operators (4 operators)
        // These increase or decrease the value by the smallest possible increment
        // The smallest increment epsilon is 1/256 = 0.00390625
        Fixed &operator++();      // Pre-increment: ++a (increments then returns)
        Fixed operator++(int);    // Post-increment: a++ (returns then increments)
        Fixed &operator--();      // Pre-decrement: --a (decrements then returns)
        Fixed operator--(int);    // Post-decrement: a-- (returns then decrements)

        // Getters and setters
        int getRawBits(void) const;
        void setRawBits(int const raw);

        // Conversion methods
        float toFloat(void) const;
        int toInt(void) const;

        // Static member functions for min/max
        // These work on references and return the smaller/larger value
        static Fixed &min(Fixed &a, Fixed &b);              // Non-const version
        static const Fixed &min(const Fixed &a, const Fixed &b);  // Const version
        static Fixed &max(Fixed &a, Fixed &b);              // Non-const version
        static const Fixed &max(const Fixed &a, const Fixed &b);  // Const version
};

// Insertion operator overload for printing
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);