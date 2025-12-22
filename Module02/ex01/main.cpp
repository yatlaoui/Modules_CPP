/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:35:08 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/22 13:10:59 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// ===== ADDITIONAL MEMBER FUNCTION TESTS =====
	std::cout << "\n--- Testing getRawBits() and setRawBits() ---" << std::endl;
	// Test getRawBits() - gets the internal fixed-point value
	Fixed e;
	std::cout << "e raw bits (default): " << e.getRawBits() << std::endl;
	// Test setRawBits() - sets the internal value directly
	e.setRawBits(256);  // 256 in raw = 1.0 in fixed-point (256/256)
	std::cout << "e after setRawBits(256): " << e << std::endl;
	e.setRawBits(512);  // 512 in raw = 2.0 in fixed-point (512/256)
	std::cout << "e after setRawBits(512): " << e << std::endl;
	// Test getRawBits() with known values
	std::cout << "b raw bits (from int 10): " << b.getRawBits() << std::endl;
	std::cout << "c raw bits (from float 42.42f): " << c.getRawBits() << std::endl;

	return (0);
}
