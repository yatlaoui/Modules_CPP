/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:54:43 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 13:32:54 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string file, std::string search, std::string replace)
{
    this->filename = file;
    this->s1 = search;
    this->s2 = replace;
    this->content = "";
}

FileReplacer::~FileReplacer(void)
{
}

bool FileReplacer::readFile(void)
{
    std::ifstream inputFile(this->filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open file '" << this->filename << "'" << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        this->content += line;
        if (!inputFile.eof())
            this->content += "\n";
    }
    inputFile.close();
    return true;
}

std::string FileReplacer::replaceAll(void)
{
    std::string result = "";
    size_t pos = 0;
    size_t foundPos = 0;
    while (pos < this->content.length())
    {
        foundPos = this->content.find(this->s1, pos);
        if (foundPos == std::string::npos)
        {
            result += this->content.substr(pos);
            break;
        }
        result += this->content.substr(pos, foundPos - pos);
        result += this->s2;
        pos = foundPos + this->s1.length();
    }
    return result;
}

bool FileReplacer::writeFile(std::string result)
{
    std::string outputFilename = this->filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create file '" << outputFilename << "'" << std::endl;
        return false;
    }
    outputFile << result;
    outputFile.close();
    std::cout << "File processed successfully!" << std::endl;
    std::cout << "Output written to: " << outputFilename << std::endl;
    return true;
}

bool FileReplacer::process(void)
{
    if (this->s1.empty())
    {
        std::cerr << "Error: Search string (s1) cannot be empty" << std::endl;
        return false;
    }
    if (!this->readFile())
        return false;
    std::string result = this->replaceAll();
    if (!this->writeFile(result))
        return false;
    return true;
}
