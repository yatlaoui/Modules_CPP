/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 00:57:00 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/26 02:04:46 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
		const std::string   _name;
		bool    _signed;
		const int   _gradeToSign;
		const int   _gradeToExecute;

    public:
        AForm(); 
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);
        
        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char *what() const throw(); 
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };  
        
};

std::ostream &operator<<(std::ostream &out, const AForm &af);
