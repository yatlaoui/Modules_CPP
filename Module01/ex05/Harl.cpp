/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:31 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/16 17:45:32 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl(void) {}

// Destructor
Harl::~Harl(void) {}

// debug: DEBUG level complaint
void Harl::debug(void)
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

// info: INFO level complaint
void Harl::info(void)
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

// warning: WARNING level complaint
void Harl::warning(void)
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

// error: ERROR level complaint
void Harl::error(void)
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

// complain: calls the appropriate function based on level
// KEY CONCEPT: Uses POINTERS TO MEMBER FUNCTIONS
void Harl::complain(std::string level)
{
    // Array of level names
    // This allows us to match the string to an index
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    // Array of POINTERS TO MEMBER FUNCTIONS
    // Syntax: void (Harl::*functionName)(void)
    // This means: pointer to a member function of Harl that returns void and takes no parameters
    void (Harl::*functions[4])(void) = {
        &Harl::debug,      // Address of debug function
        &Harl::info,       // Address of info function
        &Harl::warning,    // Address of warning function
        &Harl::error       // Address of error function
    };

    // Loop through the levels to find a match
    for (int i = 0; i < 4; i++)
    {
        // If the level matches
        if (levels[i] == level)
        {
            // Call the function using the pointer
            // Syntax: (this->*functions[i])()
            // this->*functions[i] dereferences the pointer to member function
            // () calls the function
            (this->*functions[i])();
            return;  // Exit after calling the function
        }
    }

    // If no match was found
    std::cout << "[UNKNOWN] Invalid complaint level: " << level << std::endl;
}

// WHY USE POINTERS TO MEMBER FUNCTIONS?
// 1. Avoids a forest of if/else statements
// 2. More elegant and maintainable
// 3. Easy to add new levels (just add to arrays)
// 4. Demonstrates advanced C++ features
//
// SYNTAX BREAKDOWN:
// void (Harl::*ptr)(void) - declares a pointer to member function
// &Harl::debug - gets address of member function
// (this->*ptr)() - calls the member function through the pointer
