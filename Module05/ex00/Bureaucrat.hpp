/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:10:51 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/23 22:50:51 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
    
        const std::string &getName() const; //1er const, peut lire la string mais pas la modifier, 2e, on ne mdofie ni grade ni name
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
    
        class GradeTooHighException : public std::exception //gradetoo herite de std::exception, on crée notr epopre type d'errur, 
        {
            public:
                virtual const char *what() const throw(); //virtual pour Pour remplacer la version de what() déjà présente dans std::exception.
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw(); //what doit retourner un texte c, le nom whatt ne peut pas etre changé c'est une fonction de std::exepction
        };  
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
