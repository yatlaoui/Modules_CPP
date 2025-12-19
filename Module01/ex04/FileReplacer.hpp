/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:54:52 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:54:20 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>

class FileReplacer {
    private:
        std::string filename;
        std::string s1;
        std::string s2;
        std::string content;

        bool readFile(void);
        std::string replaceAll(void);
        bool writeFile(std::string result);
    public:
        FileReplacer(std::string file, std::string search, std::string replace);
        ~FileReplacer(void);
        bool process(void);
};

#endif
