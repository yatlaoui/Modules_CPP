/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:11 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:49:46 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(std::string humanName);
        ~HumanB(void);
        void setWeapon(Weapon& humanWeapon);
        void attack(void);
};

#endif
