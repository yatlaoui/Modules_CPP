/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:05:57 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 15:55:20 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->name = "";
    std::cout << "A nameless zombie has been created" << std::endl;
}

Zombie::~Zombie(void)
{
    if (this->name.empty())
        std::cout << "A nameless zombie has been destroyed" << std::endl;
    else
        std::cout << "Zombie " << this->name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
