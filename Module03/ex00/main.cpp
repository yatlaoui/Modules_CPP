/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:34:32 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/23 04:49:38 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Test 1: Basic Construction and Destruction ===" << std::endl;
	{
		ClapTrap clap1("Bob");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: Attack Function ===" << std::endl;
	{
		ClapTrap clap2("Alice");
		clap2.attack("target1");
		clap2.attack("target2");
		clap2.attack("target3");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: Take Damage ===" << std::endl;
	{
		ClapTrap clap3("Charlie");
		clap3.takeDamage(3);
		clap3.takeDamage(5);
		clap3.takeDamage(10);
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Be Repaired ===" << std::endl;
	{
		ClapTrap clap4("Dave");
		clap4.takeDamage(5);
		clap4.beRepaired(3);
		clap4.beRepaired(2);
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: Energy Depletion ===" << std::endl;
	{
		ClapTrap clap5("Eve");
		for (int i = 0; i < 12; i++) {
			clap5.attack("enemy");
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: Can't Act When Dead ===" << std::endl;
	{
		ClapTrap clap6("Frank");
		clap6.takeDamage(10);
		clap6.attack("enemy");
		clap6.beRepaired(5);
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: Copy Constructor ===" << std::endl;
	{
		ClapTrap clap7("Original");
		ClapTrap clap8(clap7);
		clap7.attack("target");
		clap8.attack("target");
	}
	std::cout << std::endl;

	std::cout << "=== Test 8: Assignment Operator ===" << std::endl;
	{
		ClapTrap clap9("First");
		ClapTrap clap10("Second");
		clap10 = clap9;
		clap9.attack("target");
		clap10.attack("target");
	}
	std::cout << std::endl;

	return 0;
}
