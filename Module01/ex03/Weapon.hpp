/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:21 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 10:44:31 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

//const ref explication 

class Weapon {
    private:
        std::string type;

    public:
        Weapon(std::string weaponType);
        ~Weapon(void);
        
        const std::string& getType() const;
        void setType(std::string newType);
};

#endif
