/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:09 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 10:35:07 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName)
{
    this->name = humanName;
    this->weapon = NULL;
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon& humanWeapon)
{
    this->weapon = &humanWeapon;
}

void HumanB::attack(void)
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their "
              << this->weapon->getType() << std::endl;
}

// Why pointer, not reference?

// HumanB might NOT have a weapon initially
// The weapon is set AFTER creation (via setWeapon)
// The weapon could theoretically be NULL
// Pointers can represent "no weapon" state
// Justification: Use pointers when:

// The object might NOT exist at creation
// It's set after construction
// NULL is a valid state
// You need flexibility