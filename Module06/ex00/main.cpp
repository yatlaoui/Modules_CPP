/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:08:47 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/03 14:14:11 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Usage: ./convert <literal>" << std::endl, 1);
    ScalarConverter::convert(argv[1]);
    return (0);
}
