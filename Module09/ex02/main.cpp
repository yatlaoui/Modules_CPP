/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:23:56 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/19 22:01:55 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
		return (std::cerr << "Error" << std::endl, 1);
	PmergeMe sorter;
	try
	{
		sorter.run(argc, argv);
	}
	catch (std::exception &e)
	{
		return (std::cerr << e.what() << std::endl, 1);
	}
    return (0);
}
