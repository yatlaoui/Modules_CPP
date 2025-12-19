/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:55:02 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 13:28:58 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        std::cerr << "  filename: file to process" << std::endl;
        std::cerr << "  s1: string to search for" << std::endl;
        std::cerr << "  s2: string to replace with" << std::endl;
        return 1;
    }
    FileReplacer replacer(argv[1], argv[2], argv[3]);
    if (!replacer.process())
    {
        return 1;
    }
    return 0;
}

