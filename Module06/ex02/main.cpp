/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaatlaou <yaatlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:47:11 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/17 21:13:32 by yaatlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    int i = 0;

	while (i < 4)
	{
		Base *p = generate();

		std::cout << "pointer version  : ";
		identify(p);
		std::cout << "reference version: ";
		identify(*p);
		delete p;
        i++;
	}
	return (0);
}
