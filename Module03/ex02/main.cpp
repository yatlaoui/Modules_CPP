/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:37:34 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/23 04:37:36 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Test 1: FragTrap Construction/Destruction Chaining ===" << std::endl;
	{
		FragTrap frag1("Bomber");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: HighFivesGuys Special Ability ===" << std::endl;
	{
		FragTrap frag2("Friendly");
		frag2.highFivesGuys();
		frag2.attack("target");
		frag2.highFivesGuys();
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: FragTrap Inherited Functions ===" << std::endl;
	{
		FragTrap frag3("Survivor");
		frag3.attack("enemy");
		frag3.takeDamage(40);
		frag3.beRepaired(20);
		frag3.attack("another enemy");
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Comparing All Three Classes ===" << std::endl;
	{
		std::cout << "\n--- ClapTrap ---" << std::endl;
		ClapTrap clap("Clappy");
		clap.attack("target");
		clap.takeDamage(10);
		
		std::cout << "\n--- ScavTrap ---" << std::endl;
		ScavTrap scav("Scavvy");
		scav.attack("target");
		scav.takeDamage(10);
		scav.guardGate();
		
		std::cout << "\n--- FragTrap ---" << std::endl;
		FragTrap frag("Fraggy");
		frag.attack("target");
		frag.takeDamage(10);
		frag.highFivesGuys();
		
		std::cout << "\n--- Destruction Order ---" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: FragTrap Energy Points (100) ===" << std::endl;
	{
		FragTrap frag4("Energizer");
		std::cout << "Attacking and repairing multiple times..." << std::endl;
		for (int i = 0; i < 5; i++) {
			frag4.attack("dummy");
		}
		for (int i = 0; i < 5; i++) {
			frag4.beRepaired(5);
		}
		std::cout << "Still has energy for more actions!" << std::endl;
		frag4.highFivesGuys();
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: FragTrap Copy Constructor ===" << std::endl;
	{
		FragTrap frag5("Original");
		FragTrap frag6(frag5);
		frag5.highFivesGuys();
		frag6.highFivesGuys();
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: FragTrap Stats (100 HP, 30 AD) ===" << std::endl;
	{
		FragTrap frag7("Heavy");
		frag7.attack("enemy");
		frag7.takeDamage(90);
		std::cout << "FragTrap still alive with 10 HP!" << std::endl;
		frag7.beRepaired(10);
		frag7.takeDamage(100);
	}
	std::cout << std::endl;

	return 0;
}
