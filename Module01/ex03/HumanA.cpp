/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:12 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 01:34:23 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon)
{
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their "
              << this->weapon.getType() << std::endl;
}


// Why reference, not pointer?

// HumanA is ALWAYS armed (weapon given in constructor)
// The weapon exists from creation until destruction
// The weapon never changes (same weapon object throughout)
// References cannot be NULL - perfect for this guarantee
// Justification: Use references when:

// The object ALWAYS exists
// It's provided at construction time
// It never changes to a different object
// You want to enforce these guarantees at compile-time