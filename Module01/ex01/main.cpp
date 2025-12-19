/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:05:52 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:36:36 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int hordeSize = 5;
    std::cout << "\n========== CREATING A ZOMBIE HORDE ==========" << std::endl;
    std::cout << "Creating " << hordeSize << " zombies with a single allocation..." << std::endl;
    Zombie* horde = zombieHorde(hordeSize, "HordeZombie");

    std::cout << "\n========== ALL ZOMBIES ANNOUNCE ==========" << std::endl;

    for (int i = 0; i < hordeSize; i++)
    {
        std::cout << "Zombie #" << i << ": ";
        horde[i].announce();
    }

    std::cout << "\n========== DELETING THE HORDE ==========" << std::endl;
    delete[] horde;

    std::cout << "\n========== EXPLANATION ==========" << std::endl;
    std::cout << "Key points:" << std::endl;
    std::cout << "1. new Zombie[N] creates N zombies in ONE allocation" << std::endl;
    std::cout << "2. All zombies are stored contiguously in memory" << std::endl;
    std::cout << "3. You MUST use delete[] (not delete) to free the array" << std::endl;
    std::cout << "4. delete[] calls the destructor for each zombie automatically" << std::endl;
    return 0;
}

