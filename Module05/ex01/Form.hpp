/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:01:31 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/24 00:00:56 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
		const std::string   _name;
		bool    _signed;
		const int   _gradeToSign;
		const int   _gradeToExecute;

    public:
        Form(); 
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

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

std::ostream &operator<<(std::ostream &out, const Form &f);