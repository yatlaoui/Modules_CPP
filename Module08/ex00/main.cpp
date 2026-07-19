/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:34 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 01:04:40 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "=== Test with std::vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(12);
	vec.push_back(22);
	vec.push_back(32);
	vec.push_back(42);
	try
	{
		std::vector<int>::iterator it = easyFind(vec, 32);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	try
	{
		std::list<int>::iterator it = easyFind(lst, 2);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test with std::deque ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	try
	{
		std::deque<int>::iterator it = easyFind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}
