/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:23:22 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 21:31:29 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//================================================================================
// Canonical Form
//================================================================================

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

//================================================================================
// Validation
//================================================================================

bool BitcoinExchange::isDateValid(const std::string &date) const
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

bool BitcoinExchange::isValueValid(const std::string &valueStr, double &value) const
{
	if (valueStr.empty())
		return (false);
	char *end;
	value = std::strtod(valueStr.c_str(), &end);
	if (*end != '\0')
		return (false);
	if (value < 0)
		return (std::cerr << "Error: not a positive number." << std::endl, false);
	if (value > 1000)
		return (std::cerr << "Error: too large a number." << std::endl, false);
	return (true);
}

//================================================================================
// Database Lookup
//================================================================================

double BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return (it->second);
	if (it == _database.begin())
		return (0);
	--it;
	return (it->second);
}

//================================================================================
// Database Loading
//================================================================================

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database file.");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = line.substr(0, comma);
		std::string rate = line.substr(comma + 1);
		_database[date] = std::atof(rate.c_str());
	}
}

//================================================================================
// Input Processing
//================================================================================

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string::size_type sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);
		if (!isDateValid(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		double value;
		if (!isValueValid(valueStr, value))
			continue;
		double rate = getRate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
