/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 21:35:08 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/26 07:32:23 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{

// Fixed a = 42;      // Conversion implicite int → Fixed
// Fixed b = 42.5f;   // Conversion implicite float → Fixed
// int x = a.toInt(); // Conversion explicite Fixed → int
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
// 	Fixed a(42.42f);
// // Calcul : 42.42 * 256 = 10859.52
// // Arrondi : 10859

// Fixed a(42.42f);  // Stocke 10860
// a.toFloat();      // Retourne 10860 / 256 = 42.421875
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl; // l'operateur << a Affiche "42.421875" au lieu de l'adresse mémoire
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}
