/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:45:37 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 02:54:57 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    std::cout << "\n========== TESTING HARL COMPLAINTS ==========" << std::endl;
    std::cout << "\nTesting DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << "\nTesting INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << "\nTesting WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << "\nTesting ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("INVALID");
    return (0);
}
