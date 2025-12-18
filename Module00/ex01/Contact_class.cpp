/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:40:41 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/18 12:35:21 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_class.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::fill()
{
    std::string input;

    std::cout << "First Name: ";
    while (std::getline(std::cin, input))
    {
        if (!input.empty()) { _firstName = input; break; }
        std::cout << "Cannot be empty. First Name: ";
    }
    std::cout << "Last Name: ";
    while (std::getline(std::cin, input))
    {
        if (!input.empty()) { _lastName = input; break; }
        std::cout << "Cannot be empty. Last Name: ";
    }
    std::cout << "Nickname: ";
    while (std::getline(std::cin, input))
    {
        if (!input.empty()) { _nickname = input; break; }
        std::cout << "Cannot be empty. Nickname: ";
    }
    std::cout << "Phone Number: ";
    while (std::getline(std::cin, input))
    {
        if (!input.empty()) { _phoneNumber = input; break; }
        std::cout << "Cannot be empty. Phone Number: ";
    }
    std::cout << "Darkest Secret: ";
    while (std::getline(std::cin, input))
    {
        if (!input.empty()) { _darkestSecret = input; break; }
        std::cout << "Cannot be empty. Darkest Secret: ";
    }
}

void Contact::printSummary(int index) const
{
    std::cout << std::setw(10) << index << "|";
    if (_firstName.length() > 10)
        std::cout << _firstName.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << _firstName;
    std::cout << "|";
    if (_lastName.length() > 10)
        std::cout << _lastName.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << _lastName;
    std::cout << "|";
    if (_nickname.length() > 10)
        std::cout << _nickname.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << _nickname;
    std::cout << std::endl;
}

void Contact::printDetails() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
