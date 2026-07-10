/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:47:11 by yasmine           #+#    #+#             */
/*   Updated: 2026/07/10 15:40:40 by yasmine          ###   ########.fr       */
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
		identify(p);   // pass the pointer
		std::cout << "reference version: ";
		identify(*p);  // pass what the pointer points to, as a reference
		delete p; // we used 'new' in generate(), so we must free it here
        i++;
	}
	return (0);
}
