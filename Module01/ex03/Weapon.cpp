/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:19 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:51:43 by yasmine          ###   ########.fr       */
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

const std::string& Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(std::string newType)
{
    this->type = newType;
}
