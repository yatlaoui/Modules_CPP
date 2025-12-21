/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:08:07 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/21 15:26:32 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceContent(const std::string& original_text, const std::string& target, const std::string& replacement)
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
    std::string input_filename = argv[1];
    std::string string_to_remplace = argv[2];
    std::string replacementString = argv[3];
    if (string_to_remplace.empty())
    {
        std::cerr << "Error: old_string cannot be empty" << std::endl;
        return (1);
    }
    std::ifstream inputFileStream(input_filename.c_str());
    if (!inputFileStream.is_open())
    {
        std::cerr << "Error: Cannot open file: " << input_filename<< std::endl;
        return (1);
    }
    std::string fileContent;
    std::string currentLine;
    while (std::getline(inputFileStream, currentLine))
    {
        fileContent = fileContent + currentLine;

        if (!inputFileStream.eof())
            fileContent = fileContent + "\n";
    }
    inputFileStream.close();
    std::string replacedText = replaceContent(fileContent, string_to_remplace, replacementString);
    std::string outputFilename = input_filename+ ".replace";
    std::ofstream outputFileStream(outputFilename.c_str());
    if (!outputFileStream.is_open())
    {
        std::cerr << "Error: Cannot create file: " << outputFilename << std::endl;
        return (1);
    }
    outputFileStream << replacedText;
    outputFileStream.close();
    std::cout << "Replacement complete. Output written to: " << outputFilename << std::endl;
    return (0);
}
