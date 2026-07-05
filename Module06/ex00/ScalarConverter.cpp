/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:08:42 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/05 17:16:44 by yasmine          ###   ########.fr       */
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
    std::string body = str.substr(0, str.length() - 1); //substr(début, longueur)
    char *end;
    std::strtod(body.c_str(), &end);
    return (*end == '\0');
    // True only if the WHOLE body was a valid number.
}

static bool isLiteralDouble(const std::string &str)
{
    char *end; //on déclare un ptr
    std::strtod(str.c_str(), &end); // src.c_str transforme stdtring en const char* pour utiliser strtod qui ne peut pas utiliser de stdstring; strtod lit une chaine et tant qu'elle voit un nombre elle continue puis s'arreter quand elle voit des letres, on met dans end l'adresse de la premiere lettre qu'elle va trouver et s'arreter
    return (*end == '\0' && str.find('.') != std::string::npos);
    //return true si end est 0 donc strtod a pu lire toute la chaine
    // et si il y a un point dans la chaine soit find a trouvé un point soit find renvoie npos, signifiant je n'ai rien trouvé
}

static bool isPseudoLiteral(const std::string &str)
{
    return (str == "-inff" || str == "+inff" || str == "nanf"
        || str == "-inf" || str == "+inf" || str == "nan");
}

//=========================================================================
// Conversion Output
//=========================================================================

// On prend un double comme base unique parce que c’est le type le plus “universel” 
//pour parser et représenter des nombres en C++. (float est moins precis que double qui a plus de range)

// On utilise double parce que :

// il accepte presque tous les formats numériques
// il est le résultat de strtod
// il sert de base unique pour toutes les conversions
// il évite de gérer 4 parsers différents
static void PrintFloatingValue(double d) //on recoit un nombre décimal
{
    std::cout << d;
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<long>(d)) //dernire condition vérifie si le nombre est entier ou pas (42.0 == 42 or 42.5 != 42)
        std::cout << ".0";
}

static void PrintAll(double d)
{
    // ---- Char ----
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d))) //on vérifie si il est printable, si cest un ascii, is print prend un int,
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl; //o, verti le double en char
    
    // ---- Int ----
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    // --- Float ----
    std::cout << "float: ";
    PrintFloatingValue(static_cast<float>(d)); //apres appel de printfloatingvalie, si le double est tres precis, float lui donnera moins de precision
    std::cout << "f" << std::endl;

    // ---- Double ----
    std::cout << "double: ";
    PrintFloatingValue(d); //c'est deja un double pas besoin de le cast
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
        value = static_cast<double>(literal[0]); //?? on cast en double, on separe char des autres car c'estuun char et les autres sont des nombres
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
