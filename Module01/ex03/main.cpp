/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:17 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 10:35:16 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    std::cout << "\n========== TESTING HumanA (with REFERENCE) ==========" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    std::cout << "\n========== TESTING HumanB (with POINTER) ==========" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    std::cout << "\n========== KEY DIFFERENCES ==========" << std::endl;
    std::cout << "HumanA (uses REFERENCE &):" << std::endl;
    std::cout << "  - MUST have a weapon from the start" << std::endl;
    std::cout << "  - Weapon given in constructor" << std::endl;
    std::cout << "  - Reference cannot be NULL" << std::endl;
    std::cout << "  - Use when: object ALWAYS exists" << std::endl;

    std::cout << "\nHumanB (uses POINTER *):" << std::endl;
    std::cout << "  - Can start WITHOUT a weapon" << std::endl;
    std::cout << "  - Weapon set later with setWeapon()" << std::endl;
    std::cout << "  - Pointer can be NULL" << std::endl;
    std::cout << "  - Use when: object MIGHT NOT exist" << std::endl;

    std::cout << "\nBoth see weapon type changes because:" << std::endl;
    std::cout << "  - References and pointers both refer to the SAME object" << std::endl;
    std::cout << "  - When the original changes, they see the change" << std::endl;

    return 0;
}

// Key Learning Points
// References: Use when object ALWAYS exists, never NULL
// Pointers: Use when object MIGHT NOT exist, can be NULL
// Both see changes to the original object (not copies)
// Design choice affects API and guarantees
// References provide stronger compile-time guarantees
// Real-World Analogy
// HumanA = A soldier always armed (gun is part of uniform)
// HumanB = A civilian who might pick up a weapon later



// un crash sur l'ex03 lorsque la weapon est set a NULL, et ca crash !