/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:19 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 10:44:24 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
    this->type = weaponType;
}

Weapon::~Weapon(void)
{
}


// getType() returns const reference:
// const prevents caller from modifying the type
// & avoids copying the string (efficient)
// This is the recommended pattern for returning member strings
const std::string& Weapon::getType(void) const
{
    return this->type;
}
// 
void Weapon::setType(std::string newType)
{
    this->type = newType;
}
