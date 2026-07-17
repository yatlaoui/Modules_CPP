/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:32:32 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/15 23:03:16 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	// Test 1: read-only over an int array
	int tab[] = {0, 1, 2, 3, 4};
	std::cout << "int array (print):     ";
	iter(tab, 5, print<int>);
	std::cout << std::endl;

	// Test 2: mutate the int array, then print it again
	iter(tab, 5, increment<int>);
	std::cout << "int array (after +1):  ";
	iter(tab, 5, print<int>);
	std::cout << std::endl;

	// Test 3: array of doubles
	double tab2[] = {1.5, 2.5, 3.5};
	std::cout << "double array (print):  ";
	iter(tab2, 3, print<double>);
	std::cout << std::endl;

	// Test 4: const array -> only the read-only function makes sense
	int const tab3[] = {10, 20, 30};
	std::cout << "const int array:       ";
	iter(tab3, 3, print<int>);
	std::cout << std::endl;

	return(0);
}
