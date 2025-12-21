/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:37:06 by yaatlaou          #+#    #+#             */
/*   Updated: 2025/12/20 22:36:51 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "iostream"
#include "iomanip"
#include "string"

class Zombie{
    private:
        std::string _name;

    public:
        Zombie(std::string zombieName);
        ~Zombie(void);
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif