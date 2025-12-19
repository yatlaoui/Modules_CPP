/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:37:03 by yaatlaou          #+#    #+#             */
/*   Updated: 2025/12/19 10:22:24 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie::Zombie(void)
// {  
//     Zombie(std::string name) : (_name)
//     {
//         std::cout << "Zombie" << this->_name << "is born" << std::endl;
//     }
// };

// Zombie::~Zombie(void)
// {
//     std::count << "Zombie" << this->_name << "died" << std::endl;
// }


Zombie::Zombie(std::string zombieName)
{
    this->_name = zombieName;
    std::cout << "Zombie " << this->_name << " has been created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}