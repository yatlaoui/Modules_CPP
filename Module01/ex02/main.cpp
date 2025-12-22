/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:02:00 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/22 08:18:29 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

// A pointer stores the address of a variable
// A reference is another name for the same variable
// Accessing a pointer requires dereferencing (*), while a reference is used directly
// A pointer can be NULL, a reference cannot

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "========== MEMORY ADDRESSES ==========" << std::endl;
    std::cout << "Memory address of brain variable: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "\n========== VALUES ==========" << std::endl;
    std::cout << "Value of brain variable:     " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return(0);
}
