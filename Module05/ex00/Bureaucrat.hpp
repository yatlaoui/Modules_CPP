/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:10:51 by yasmine           #+#    #+#             */
/*   Updated: 2026/01/18 15:32:04 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        std::string const name;
    public:
        Bureaucrat();
        ~Bureaucrat();
        // getName();
        // getGrade():
        
};

// std::ostream &operator<<(std::ostream &out, const Fixed &fixed)

// Bureaucrat::GradeTooHighException
// Bureaucrat::GradeTooLowException