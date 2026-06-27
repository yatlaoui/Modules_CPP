/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:47:29 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/27 15:05:27 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *form;

    std::cout << "=== Test 1: Robotomy request form ===" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

    std::cout << "\n=== Test 2: Shrubbery creation form ===" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "\n=== Test 3: Presidential pardon form ===" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Criminel");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

    std::cout << "\n=== Test 4: Unknown form ===" << std::endl;
	form = someRandomIntern.makeForm("Unknown form", "John");
	if (form)
	{
		std::cout << *form << std::endl;
		delete form;
	}

    return (0);
}
