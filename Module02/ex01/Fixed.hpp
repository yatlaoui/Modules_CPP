/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:35:05 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/26 06:45:02 by yasmine          ###   ########.fr       */
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
        Fixed();
        // Constructeur depuis int
        Fixed(const int value);
        // Constructeur depuis un float
        Fixed(const float value);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        // Conversion vers float
        float toFloat(void) const;
        // Conversion vers int
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
