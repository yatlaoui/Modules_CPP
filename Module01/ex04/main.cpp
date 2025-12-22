/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:08:07 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/22 08:36:01 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// find : returns index of start of first occurrence. If found, returns the index where it begins. If not, returns npos.
// ifstream : reads the file
// ofstream : writes in file
// c_str : transforms string in const char*

std::string replace(const std::string& original_text, const std::string& target, const std::string& replacement)
{
    std::string modified_text;
    size_t search_start_index = 0;
    size_t found_index;

    while ((found_index = original_text.find(target, search_start_index)) != std::string::npos)
    {
        modified_text = modified_text + original_text.substr(search_start_index, found_index - search_start_index);
        modified_text = modified_text + replacement;
        search_start_index = found_index + target.length();
    }
    modified_text = modified_text + original_text.substr(search_start_index);
    return (modified_text);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Usage: " << argv[0] << " <filename> <old_string> <new_string>" << std::endl;
        return (1);
    }
    std::string original_file = argv[1];
    std::string old_string = argv[2];
    std::string new_string = argv[3];
    if (old_string.empty())
    {
        std::cerr << "Error: old_string cannot be empty" << std::endl;
        return (1);
    }
    std::ifstream inputFileStream(original_file.c_str());
    if (!inputFileStream.is_open())
    {
        std::cerr << "Error: Cannot open file: " << original_file << std::endl;
        return (1);
    }
    std::string content;
    std::string current_line;
    while (std::getline(inputFileStream, current_line))
    {
        content = content + current_line;
        if (!inputFileStream.eof())
            content = content + "\n";
    }
    inputFileStream.close();
    std::string replacedText = replace(content, old_string, new_string);
    std::string new_file = original_file + ".replace";
    std::ofstream outputFileStream(new_file.c_str());
    if (!outputFileStream.is_open())
    {
        std::cerr << "Error: Cannot create file: " << new_file << std::endl;
        return (1);
    }
    outputFileStream << replacedText;
    outputFileStream.close();
    std::cout << "Replacement complete. Output written to: " << new_file << std::endl;
    return (0);
}
