/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:37:17 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/25 01:30:06 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== FragTrap Construction/Destruction Test ===" << std::endl;
	{
		FragTrap frag1("A");
	}
	std::cout << std::endl;
	
	std::cout << "=== HighFivesGuys Function Test ===" << std::endl;
	{
		FragTrap frag2("B");
		frag2.highFivesGuys();
	}
	std::cout << std::endl;

	std::cout << "=== Comparing The 3 Classes ===" << std::endl;
	{
		std::cout << "--- ClapTrap ---" << std::endl;
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
	return (0);
}
