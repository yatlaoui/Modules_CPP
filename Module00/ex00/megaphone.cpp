/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:50:22 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/17 11:29:44 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}
