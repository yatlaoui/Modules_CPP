/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:36:49 by yaatlaou          #+#    #+#             */
/*   Updated: 2025/12/19 10:28:51 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// int main(void)
// {
//     Zombie* Zombies = new Zombie[3];

//     delete [] Zombies;
//     return(0);
// }

int main(void)
{
    std::cout << "\n========== TESTING HEAP ALLOCATION (newZombie) ==========" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    std::cout << "HeapZombie is still alive and can be used..." << std::endl;
    delete heapZombie;

    std::cout << "\n========== TESTING STACK ALLOCATION (randomChump) ==========" << std::endl;
    randomChump("StackZombie");

    std::cout << "StackZombie was automatically destroyed when randomChump() ended" << std::endl;
    return 0;
}