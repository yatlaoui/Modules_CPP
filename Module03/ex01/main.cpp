/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:39:14 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/24 23:25:16 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Constructor/Destructor Order Test ===" << std::endl;
	{
		ScavTrap scav1("A");
	}
	std::cout << std::endl;
	std::cout << "=== ScavTrap Attack New Message Test ===" << std::endl;
	{
		ScavTrap scav2("B");
		scav2.attack("enemy1");
	}
	std::cout << std::endl;
	std::cout << "===  GuardGate Function Test ===" << std::endl;
	{
		ScavTrap scav3("C");
		scav3.guardGate();
	}
	std::cout << std::endl;
	std::cout << "=== Inherited Functions Test ===" << std::endl;
	{
		ScavTrap scav4("D");
		scav4.takeDamage(30);
		scav4.beRepaired(20);
	}
	std::cout << std::endl;
	return 0;
}
