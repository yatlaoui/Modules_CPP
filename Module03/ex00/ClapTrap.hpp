/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:35:30 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/24 21:58:04 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		// Uses const reference for the parameter to avoid modifying the source
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		// attack function - makes the ClapTrap attack a target
		// Takes const reference to target name to avoid copying and prevent modification
		// Costs 1 energy point and requires the ClapTrap to be alive
		void attack(const std::string& target);
		// takeDamage function - reduces the ClapTrap's hit points
		// Takes unsigned int parameter representing the amount of damage
		// Can result in the ClapTrap being destroyed if hit points reach 0
		void takeDamage(unsigned int amount);
		// beRepaired function - restores hit points to the ClapTrap
		// Takes unsigned int parameter representing the amount to repair
		// Costs 1 energy point and requires the ClapTrap to be alive
		void beRepaired(unsigned int amount);
};
