/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:10:54 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/25 00:34:53 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Valid bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat jean("Jean", 50);
        std::cout << jean << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl; // "Quand une exception est lancée, stocke-la dans la variable e.", e pour exepction mais tu peux mettre la lettre que tu veux
    }
    
    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try
    {
        Bureaucrat high("BestBureaucrat", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try
    {
        Bureaucrat high("BestBureaucrat", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try
    {
        Bureaucrat low("WorstBureaucrat", 151);
        std::cout << low << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Incrementation ===" << std::endl;
    try
    {
        Bureaucrat elio("Elio", 2);
        std::cout << elio << std::endl;
        elio.incrementGrade();
		std::cout << "After incrementation: " << elio << std::endl;
		elio.incrementGrade();
		std::cout << "After incrementation: " << elio << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrementation ===" << std::endl;
    try
    {
        Bureaucrat oliver("Oliver", 149);
        std::cout << oliver << std::endl;
        oliver.decrementGrade();
		std::cout << "After decrementation: " << oliver << std::endl;
		oliver.decrementGrade();
		std::cout << "After decrementation: " << oliver << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return (0);
}
