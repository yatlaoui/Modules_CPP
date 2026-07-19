/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:23:42 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 21:51:28 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error" << std::endl, 1);
	RPN rpn;
	try
	{
		int result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception &e)
    {
		return (std::cerr << e.what() << std::endl, 1);     
    }
	return (0);
}
