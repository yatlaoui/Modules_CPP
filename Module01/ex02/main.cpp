/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:02:00 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:40:26 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;

    std::string& stringREF = brain;

    std::cout << "\n========== MEMORY ADDRESSES ==========" << std::endl;

    std::cout << "Memory address of brain variable: " << &brain << std::endl;

    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "\n========== VALUES ==========" << std::endl;

    std::cout << "Value of brain variable:     " << brain << std::endl;

    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    std::cout << "\n========== EXPLANATION ==========" << std::endl;
    std::cout << "Key differences between pointers and references:" << std::endl;
    std::cout << "\nPOINTER (stringPTR):" << std::endl;
    std::cout << "  - Stores a memory address" << std::endl;
    std::cout << "  - Use & to get an address: &brain" << std::endl;
    std::cout << "  - Use * to dereference (get value): *stringPTR" << std::endl;
    std::cout << "  - Can be reassigned to point to different variables" << std::endl;
    std::cout << "  - Can be NULL (point to nothing)" << std::endl;

    std::cout << "\nREFERENCE (stringREF):" << std::endl;
    std::cout << "  - An alias (another name) for a variable" << std::endl;
    std::cout << "  - No * needed to access value (automatic dereferencing)" << std::endl;
    std::cout << "  - Cannot be reassigned (always refers to same variable)" << std::endl;
    std::cout << "  - Cannot be NULL (must refer to something)" << std::endl;
    std::cout << "  - Safer and easier to use than pointers!" << std::endl;

    std::cout << "\nAll three addresses are IDENTICAL because:" << std::endl;
    std::cout << "- brain is the original variable at address X" << std::endl;
    std::cout << "- stringPTR stores address X" << std::endl;
    std::cout << "- stringREF is an alias for the variable at address X" << std::endl;

    return 0;
}
