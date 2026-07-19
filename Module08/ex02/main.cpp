/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 02:59:57 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 08:19:57 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "=== Subject example test ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top:  " << mstack.top() << std::endl; // 17

	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "iterating: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// A MutantStack can still be copied into a normal std::stack.
	std::stack<int> s(mstack);
	std::cout << "copied into std::stack, top: " << s.top() << std::endl;

	std::cout << "\n=== Same data in a std::list (for comparison) ===" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "iterating: ";
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
		std::cout << *lit << " ";
	std::cout << std::endl;

	std::cout << "\n=== Reverse iteration test ===" << std::endl;
	MutantStack<int> ms2;
	for (int i = 1; i <= 5; ++i)
		ms2.push(i);
	std::cout << "reversed: ";
	for (MutantStack<int>::reverse_iterator rit = ms2.rbegin(); rit != ms2.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	return (0);
}
