/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:34 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/18 02:05:49 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	// --- Test 1: a vector of ints ---
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "=== Test with std::vector ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Value that does NOT exist -> should throw
	try
	{
		easyfind(vec, 99);
		std::cout << "Found 99 (this should not happen)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// --- Test 2: a list of ints (same function works!) ---
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << "\n=== Test with std::list ===" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
