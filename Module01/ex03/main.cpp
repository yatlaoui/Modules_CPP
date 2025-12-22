/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:17 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/22 07:23:11 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    // Reference
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club); // Weapon must be provided
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    // Pointer
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim"); // No weapon yet
        jim.setWeapon(club); // Set weapon later
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return (0);
}
