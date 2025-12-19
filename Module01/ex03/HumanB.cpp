/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:09 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:48:59 by yasmine          ###   ########.fr       */
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
