/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:36:07 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/23 04:36:09 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() 
{
	std::cout << "=== Test 1: Construction/Destruction Chaining ===" << std::endl;
	{
		ScavTrap scav1("Guardian");
	}
	std::cout << std::endl;

	std::cout << "=== Test 2: ScavTrap Attack (different message) ===" << std::endl;
	{
		ScavTrap scav2("Warrior");
		scav2.attack("enemy1");
		scav2.attack("enemy2");
	}
	std::cout << std::endl;

	std::cout << "=== Test 3: GuardGate Special Ability ===" << std::endl;
	{
		ScavTrap scav3("Protector");
		scav3.guardGate();
		scav3.attack("intruder");
		scav3.guardGate();
	}
	std::cout << std::endl;

	std::cout << "=== Test 4: Inherited Functions (takeDamage, beRepaired) ===" << std::endl;
	{
		ScavTrap scav4("Tank");
		scav4.takeDamage(30);
		scav4.beRepaired(20);
		scav4.attack("target");
	}
	std::cout << std::endl;

	std::cout << "=== Test 5: ScavTrap vs ClapTrap Stats ===" << std::endl;
	{
		std::cout << "Creating ClapTrap:" << std::endl;
		ClapTrap clap("Clappy");
		clap.attack("test");
		
		std::cout << "\nCreating ScavTrap:" << std::endl;
		ScavTrap scav("Scavvy");
		scav.attack("test");
		
		std::cout << "\nTaking massive damage:" << std::endl;
		clap.takeDamage(10);
		scav.takeDamage(10);
	}
	std::cout << std::endl;

	std::cout << "=== Test 6: Energy Depletion ===" << std::endl;
	{
		ScavTrap scav5("Energetic");
		for (int i = 0; i < 52; i++) {
			if (i == 49)
				std::cout << "... (skipping middle attacks) ..." << std::endl;
			if (i < 2 || i >= 49)
				scav5.attack("dummy");
		}
	}
	std::cout << std::endl;

	std::cout << "=== Test 7: Copy Constructor ===" << std::endl;
	{
		ScavTrap scav6("Original");
		ScavTrap scav7(scav6);
		scav6.guardGate();
		scav7.guardGate();
	}
	std::cout << std::endl;

	return 0;
}
