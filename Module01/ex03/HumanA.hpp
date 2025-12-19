/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:14 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:43:07 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon;

    public:
        HumanA(std::string humanName, Weapon& humanWeapon);
        ~HumanA(void);
        void attack(void);
};

#endif
