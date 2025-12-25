/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:34:32 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/24 22:16:08 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== Attack Function Test ===" << std::endl;
	{
		ClapTrap clap1("A");
		clap1.attack("target1");
		clap1.attack("target2");
		clap1.attack("target3");
	}
	std::cout << std::endl;
	std::cout << "=== Take Damage Function Test ===" << std::endl;
	{
		ClapTrap clap2("B");
		clap2.takeDamage(3);
		clap2.takeDamage(5);
		clap2.takeDamage(10);
	}
	std::cout << std::endl;
	std::cout << "=== Be Repaired Function Test ===" << std::endl;
	{
		ClapTrap clap3("C");
		clap3.takeDamage(5);
		clap3.beRepaired(3);
		clap3.beRepaired(2);
	}
	std::cout << std::endl;
	std::cout << "=== No More Energy Test ===" << std::endl;
	{
		ClapTrap clap4("D");
		for (int i = 0; i < 12; i++)
			clap4.attack("enemy");
	}
	std::cout << std::endl;
	std::cout << "=== ClapTrap No More Test ===" << std::endl;
	{
		ClapTrap clap5("E");
		clap5.takeDamage(10);
		clap5.attack("enemy");
		clap5.beRepaired(5);
	}
	std::cout << std::endl;
	return (0);
}
