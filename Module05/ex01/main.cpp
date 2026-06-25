/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:10:54 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/25 23:42:06 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Test 1: Valid form ===" << std::endl;
    try
    {
        Form jean("Jean", 50, 25);
        std::cout << jean << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try
    {
        Form high("BestForm", 0, 25);
        std::cout << high << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try
    {
        Form low("WorstForm", 50, 151);
        std::cout << low << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Bureaucrat signs the form ===" << std::endl;
    try
    {
        Bureaucrat worthy("B.Worthy", 65);
        Form paper("Paper", 70, 66);
        std::cout << worthy << std::endl;
        std::cout << paper << std::endl;
        worthy.signForm(paper);
        std::cout << paper << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Bureaucrat can't sign form (grade too low) ===" << std::endl;
    try
    {
        Bureaucrat unworthy("B.Unworthy", 140);
        Form contract("Contract", 2, 25);
        std::cout << unworthy << std::endl;
        std::cout << contract << std::endl;
        unworthy.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
	try
	{
		Form original("Original", 50, 25);
		Form copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return (0);
}
