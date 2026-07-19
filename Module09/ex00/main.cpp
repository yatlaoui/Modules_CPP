/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:23:31 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 19:14:07 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	BitcoinExchange btc;
	try
    {
        btc.loadDatabase("data.csv");
    }
	catch (std::exception &e)
    {
        return(std::cerr << "Error: " << e.what() << std::endl, 1);
    }
	btc.processInput(argv[1]);
    return (0);
}
