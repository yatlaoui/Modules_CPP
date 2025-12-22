/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:05:52 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 15:55:53 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int hordeSize = 10;
    Zombie* horde = zombieHorde(hordeSize, "HordeZombie");

    for (int i = 0; i < hordeSize; i++)
    {
        std::cout << "Zombie #" << i << ": ";
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}

