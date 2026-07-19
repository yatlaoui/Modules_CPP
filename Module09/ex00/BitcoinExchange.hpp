/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:23:28 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 21:18:27 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;
        bool isDateValid(const std::string &date) const;
        bool isValueValid(const std::string &valueStr, double &value) const;
        double getRate(const std::string &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename);
};
