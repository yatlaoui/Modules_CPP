/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:37 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:57:44 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    std::cout << "\n========== TESTING HARL COMPLAINTS ==========" << std::endl;
    std::cout << "\nTesting DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << "\nTesting INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << "\nTesting WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << "\nTesting ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("INVALID");
    return 0;
}


// int main()
// {
// 	Harl	harl;

// 	std::cout << "Printing all harl could say." << std::endl << std::endl;
// 	harl.complain("ERROR");
// 	std::cout << std::endl;
// 	harl.complain("WARNING");
// 	std::cout << std::endl;
// 	harl.complain("INFO");
// 	std::cout << std::endl;
// 	harl.complain("DEBUG");
// 	std::cout << std::endl;
// 	harl.complain("something else");
// 	std::cout << std::endl;
// 	std::cout << "Now you have 5 chances to make harl say something." << std::endl;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		std::cout << "input: ";
// 		std::string input;
// 		getline(std::cin, input);
// 		if (std::cin.eof() == true)
// 		{
// 			std::cerr << "^D" << std::endl;
// 			exit(EXIT_FAILURE);
// 		}
// 		harl.complain(input);
// 		std::cout << std::endl;
// 	}
// 	return (EXIT_SUCCESS);
// } 