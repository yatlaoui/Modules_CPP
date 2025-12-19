/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:55:02 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/16 17:55:04 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"  // Include our FileReplacer class
#include <iostream>           // For std::cout, std::cerr

// Main function: entry point of the program
// Takes command line arguments:
// - argv[0]: program name (automatically provided)
// - argv[1]: filename (input file to process)
// - argv[2]: s1 (string to search for)
// - argv[3]: s2 (string to replace with)
int main(int argc, char **argv)
{
    // Check if we have exactly 3 arguments (plus program name = 4 total)
    // argc = argument count
    // We need: ./program filename s1 s2
    if (argc != 4)
    {
        // Print usage message to standard error
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        std::cerr << "  filename: file to process" << std::endl;
        std::cerr << "  s1: string to search for" << std::endl;
        std::cerr << "  s2: string to replace with" << std::endl;
        return 1;  // Return error code
    }

    // Create a FileReplacer object with the command line arguments
    // argv[1] = filename
    // argv[2] = search string (s1)
    // argv[3] = replacement string (s2)
    FileReplacer replacer(argv[1], argv[2], argv[3]);

    // Process the file (read, replace, write)
    // The process() function returns true on success, false on error
    if (!replacer.process())
    {
        // If process() returned false, an error occurred
        // The FileReplacer class already printed an error message
        return 1;  // Return error code
    }

    // Success! Return 0 to indicate everything went well
    return 0;
}

// IMPROVED DESIGN BENEFITS:
// 1. Separation of concerns: FileReplacer handles logic, main handles arguments
// 2. Reusability: FileReplacer can be used in other programs
// 3. Testability: Each function can be tested independently
// 4. Readability: main() is clean and easy to understand
// 5. Maintainability: Changes to logic only affect FileReplacer.cpp
