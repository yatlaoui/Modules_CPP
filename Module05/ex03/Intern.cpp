/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 10:51:34 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/27 14:16:43 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}
        
Intern::~Intern(){}

AForm *Intern::createShrubbery(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}
    
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*formCreators[3])(const std::string &) const = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            AForm *form = ((this->*formCreators[i])(target));
            std::cout << "Intern creates " << form->getName() << std::endl;
            return (form);
        }
    }
    std::cout << "Error: Form '" << formName << "' does not exist." << std::endl;
    return (NULL);
}
