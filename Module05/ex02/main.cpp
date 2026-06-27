/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:47:29 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/27 11:36:43 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	// try
	// {
	// 	Bureaucrat bob("Bob", 130);
	// 	ShrubberyCreationForm shrubs("garden");
	// 	std::cout << bob << std::endl;
	// 	std::cout << shrubs << std::endl;
	// 	bob.signForm(shrubs);     // 130 <= 145 -> signed
	// 	bob.executeForm(shrubs);  // 130 <= 137 -> executes (creates the file)
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }

    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat li("Li", 40);
		RobotomyRequestForm robot("Bender");
		std::cout << li << std::endl;
		std::cout << robot << std::endl;
		li.signForm(robot);    // 40 <= 72 -> signed
		li.executeForm(robot); // 40 <= 45 -> executes (50/50 result)
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Tristan");
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		president.signForm(pardon);    // 1 <= 25 -> signed
		president.executeForm(pardon); // 1 <= 5  -> executes (prints the pardon)
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test 4: Execute unsigned form ===" << std::endl;
	try
	{
		Bureaucrat john("John", 1);
		PresidentialPardonForm pardon("Criminal");
		std::cout << john << std::endl;
		std::cout << pardon << std::endl;
		john.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

    return (0);
}
