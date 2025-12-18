/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:23:56 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/17 11:40:01 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_class.hpp"

int main(void)
{
    PhoneBook 	PhoneBook;
    std::string command;

    while (true)
    {
        std::cout << "[MyAwesomePhoneBook] ADD, SEARCH or EXIT: ";
        if (!std::getline(std::cin, command))
        {
            if (std::cin.eof())
                exit(0);
            break;
        }
        if (command == "ADD")
            PhoneBook.add();
        else if (command == "SEARCH")
            PhoneBook.search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command." << std::endl;
    }
    return 0;
}
