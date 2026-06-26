/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:08:40 by yasmine           #+#    #+#             */
/*   Updated: 2026/06/26 19:13:51 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

class ScalarConverter
{
    private:
        int _number;
    public:
        int convert(std::string literal);
};
