/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:51:47 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 21:41:17 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(Fixed const &copy);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
