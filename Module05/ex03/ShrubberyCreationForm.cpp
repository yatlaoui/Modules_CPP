/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:55:38 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/27 10:13:11 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
	{
		AForm::operator=(other); //assigns base-class part (_signed)
		_target = other._target; //assigns derived part
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::exectueAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Can't create file" << std::endl;
        return;
    }
    file << "        *" << std::endl;
    file << "       ***" << std::endl;
    file << "      *****" << std::endl;
    file << "     *******" << std::endl;
    file << "    *********" << std::endl;
    file << "       |||" << std::endl;
    file << std::endl;
    file << "        *" << std::endl;
    file << "       ***" << std::endl;
    file << "      *****" << std::endl;
    file << "     *******" << std::endl;
    file << "    *********" << std::endl;
    file << "       |||" << std::endl;
    file.close();
}
