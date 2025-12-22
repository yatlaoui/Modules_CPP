/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:52:15 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/22 13:11:55 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
    
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;


	// ===== ADDITIONAL MEMBER FUNCTION TESTS =====
	std::cout << "\n--- Testing Comparison Operators ---" << std::endl;
	Fixed x(5);
	Fixed y(10);
	Fixed z(5);

	std::cout << "x=" << x << ", y=" << y << ", z=" << z << std::endl;
	std::cout << "x > y: " << (x > y) << std::endl;
	std::cout << "x < y: " << (x < y) << std::endl;
	std::cout << "x >= z: " << (x >= z) << std::endl;
	std::cout << "x <= y: " << (x <= y) << std::endl;
	std::cout << "x == z: " << (x == z) << std::endl;
	std::cout << "x != y: " << (x != y) << std::endl;

	std::cout << "\n--- Testing Arithmetic Operators ---" << std::endl;
	Fixed n1(10);
	Fixed n2(3);

	std::cout << "n1=" << n1 << ", n2=" << n2 << std::endl;
	std::cout << "n1 + n2 = " << (n1 + n2) << std::endl;
	std::cout << "n1 - n2 = " << (n1 - n2) << std::endl;
	std::cout << "n1 * n2 = " << (n1 * n2) << std::endl;
	std::cout << "n1 / n2 = " << (n1 / n2) << std::endl;

	std::cout << "\n--- Testing Increment/Decrement Operators ---" << std::endl;
	Fixed counter(5);

	std::cout << "counter start: " << counter << std::endl;
	std::cout << "++counter: " << ++counter << std::endl;
	std::cout << "counter: " << counter << std::endl;
	std::cout << "counter++: " << counter++ << std::endl;
	std::cout << "counter: " << counter << std::endl;
	std::cout << "--counter: " << --counter << std::endl;
	std::cout << "counter: " << counter << std::endl;
	std::cout << "counter--: " << counter-- << std::endl;
	std::cout << "counter: " << counter << std::endl;

	std::cout << "\n--- Testing getRawBits() and setRawBits() ---" << std::endl;
	Fixed raw;

	std::cout << "raw default: " << raw.getRawBits() << std::endl;
	raw.setRawBits(1024);
	std::cout << "raw after setRawBits(1024): " << raw << std::endl;
	std::cout << "raw bits: " << raw.getRawBits() << std::endl;

	std::cout << "\n--- Testing min/max Static Functions ---" << std::endl;
	Fixed m1(15.5f);
	Fixed m2(20.3f);

	std::cout << "m1=" << m1 << ", m2=" << m2 << std::endl;
	std::cout << "Fixed::min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "Fixed::max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	// Test const versions
	const Fixed cm1(100);
	const Fixed cm2(50);
	std::cout << "cm1=" << cm1 << ", cm2=" << cm2 << std::endl;
	std::cout << "Fixed::min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "Fixed::max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;
	
	return (0);
}
