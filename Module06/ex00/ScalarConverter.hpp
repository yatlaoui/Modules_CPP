/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:08:40 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/01 21:13:03 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include <cstdlib>
#include <climits>
#include <cmath>   

// the class stores nothing, so we hide all 4 special members (constructors, destructor, =)
// under private. Result: nobody can create an object;
// you only call ScalarConverter::convert(...) 
// (a static method = belongs to the class, not to an object).

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &literal);
};
