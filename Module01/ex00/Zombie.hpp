/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:37:06 by yaatlaou          #+#    #+#             */
/*   Updated: 2025/12/18 15:49:03 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "iostream"

class Zombie
{
    private:
    std::string name;
    

    public:
    Zombie(void);
    ~Zombie(void);
    void announce(void);
};

#endif