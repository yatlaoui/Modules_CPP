/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:40:09 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/18 13:53:16 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_class.hpp"

PhoneBook::PhoneBook(void)
{
    this->_count = 0;
    this->_next = 0;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::add()
{
    _contacts[_next].fill();
    _next = (_next + 1) % 8;
    if (_count < 8)
        _count++;
}

void PhoneBook::search() const
{
    if (_count == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    for (int i = 0; i < _count; i++)
        _contacts[i].printSummary(i);
    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty() || !isdigit(input[0]))
    {
        std::cout << "Invalid input.\n";
        return;
    }
    int index = std::stoi(input);
    if (index < 0 || index >= _count)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    _contacts[index].printDetails();
}
