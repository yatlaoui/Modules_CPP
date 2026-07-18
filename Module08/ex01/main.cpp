/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:45 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 00:18:13 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	// --- Test 1: the exact example from the subject ---
	std::cout << "=== Subject example ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // expect 2
	std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;  // expect 14

	// --- Test 2: adding one too many -> should throw ---
	std::cout << "\n=== Overflow test ===" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// --- Test 3: not enough numbers -> should throw ---
	std::cout << "\n=== Too few numbers test ===" << std::endl;
	try
	{
		Span small(1);
		small.addNumber(1);
		small.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// // --- Test 4: big test with 10,000+ numbers ---
	// std::cout << "\n=== Big test (10000 numbers) ===" << std::endl;
	// Span big(10000);
	// std::vector<int> lots;
	// for (int i = 0; i < 10000; ++i)
	// 	lots.push_back(i * 3); // 0, 3, 6, 9 ...
	// big.addRange(lots.begin(), lots.end());
	// std::cout << "shortestSpan: " << big.shortestSpan() << std::endl; // 3
	// std::cout << "longestSpan:  " << big.longestSpan() << std::endl;  // 29997

	return (0);
}
