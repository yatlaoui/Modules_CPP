/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:08:42 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/17 21:11:49 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &){return (*this);}
ScalarConverter::~ScalarConverter(){}

//=========================================================================
// Literal Type Detection
//=========================================================================

static bool isLiteralChar(const std::string &str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool isLiteralInt(const std::string &str)
{
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (i == str.length())
        return (false);
    while (i  < str.length())
    {
        if (!std::isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool isLiteralFloat(const std::string &str)
{
    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return (false);
    std::string body = str.substr(0, str.length() - 1);
    char *end;
    std::strtod(body.c_str(), &end);
    return (*end == '\0');
}

static bool isLiteralDouble(const std::string &str)
{
    char *end;
    std::strtod(str.c_str(), &end);
    return (*end == '\0' && str.find('.') != std::string::npos);
}

static bool isPseudoLiteral(const std::string &str)
{
    return (str == "-inff" || str == "+inff" || str == "nanf"
        || str == "-inf" || str == "+inf" || str == "nan");
}

//=========================================================================
// Conversion Output
//=========================================================================

static void PrintFloatingValue(double d)
{
    std::cout << d;
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<long>(d))
        std::cout << ".0";
}

static void PrintAll(double d)
{
    // ---- Char ----
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    
    // ---- Int ----
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    // --- Float ----
    std::cout << "float: ";
    PrintFloatingValue(static_cast<float>(d));
    std::cout << "f" << std::endl;

    // ---- Double ----
    std::cout << "double: ";
    PrintFloatingValue(d);
    std::cout << std::endl;
}

//=========================================================================
// The Public Entry Point (reads one literal and prints it's 4 conversions)
//=========================================================================

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
        return;
    if (isPseudoLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan" || literal == "nanf")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
        else
        {
            std::string sign = (literal[0] == '-') ? "-" : "+";
			std::cout << "float: " << sign << "inff" << std::endl;
			std::cout << "double: " << sign << "inf" << std::endl; 
        }
        return;
    }
    double value;
    if (isLiteralChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isLiteralDouble(literal) || isLiteralFloat(literal) || isLiteralInt(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    PrintAll(value);
}
