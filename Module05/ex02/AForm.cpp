/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 00:57:05 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/27 11:14:50 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm(){}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
} 
 
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute) 
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm " << f.getName()
		<< " [signed: " << (f.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute() << "]";
	return out;
}
