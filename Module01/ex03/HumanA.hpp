/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:14 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/22 07:15:42 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

// Reference:
// HumanA ALWAYS armed (weapon given in constructor)
// The weapon exists from creation until destruction
// The weapon never changes
// Reference cannot be NULL 

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
