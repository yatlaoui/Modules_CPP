/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 10:51:31 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/27 14:14:43 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class Intern
{
    private:
        AForm *createShrubbery(const std::string &target) const;
        AForm *createRobotomy(const std::string &target) const;
        AForm *createPresidential(const std::string &target) const;

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
    
       AForm *makeForm(const std::string &formName, const std::string &target); 
};
