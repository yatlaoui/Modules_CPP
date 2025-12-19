/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine <yasmine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:54:43 by yasmine           #+#    #+#             */
/*   Updated: 2025/12/19 10:53:18 by yasmine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

// Constructor: initializes the FileReplacer with parameters
FileReplacer::FileReplacer(std::string file, std::string search, std::string replace)
{
    // Store the parameters in private attributes
    this->filename = file;
    this->s1 = search;
    this->s2 = replace;
    this->content = "";  // Initialize content as empty
}

// Destructor: nothing special to clean up
FileReplacer::~FileReplacer(void)
{
    // No dynamic memory allocated, so nothing to delete
}

// readFile: reads the entire file content into the content attribute
// Returns true on success, false on failure
bool FileReplacer::readFile(void)
{
    // Open the file for reading
    // .c_str() converts std::string to C-style string (const char*)
    std::ifstream inputFile(this->filename.c_str());

    // Check if the file opened successfully
    if (!inputFile.is_open())
    {
        // Print error message to standard error stream
        std::cerr << "Error: Cannot open file '" << this->filename << "'" << std::endl;
        return false;  // Return false to indicate failure
    }

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line))
    {
        // Append the line to content
        this->content += line;

        // Add a newline if we're not at the end of file
        // This preserves the original file structure
        if (!inputFile.eof())
            this->content += "\n";
    }

    // Close the file (good practice, though destructor would do it)
    inputFile.close();

    // Return true to indicate success
    return true;
}

// replaceAll: replaces all occurrences of s1 with s2 in content
// Returns the modified string
std::string FileReplacer::replaceAll(void)
{
    // Result string to build the modified content
    std::string result = "";

    // Position variables for searching
    size_t pos = 0;          // Current position in the content string
    size_t foundPos = 0;     // Position where s1 is found

    // Loop through the entire content string
    while (pos < this->content.length())
    {
        // Search for s1 starting from current position
        // find() returns the position of first occurrence, or std::string::npos if not found
        foundPos = this->content.find(this->s1, pos);

        // If s1 is not found anymore
        if (foundPos == std::string::npos)
        {
            // Append the rest of the string (from pos to end)
            // substr(pos) extracts substring from pos to end
            result += this->content.substr(pos);
            break;  // Exit the loop
        }

        // s1 was found at foundPos!
        // First, copy everything BEFORE the found position
        // substr(pos, foundPos - pos) extracts substring from pos with length (foundPos - pos)
        result += this->content.substr(pos, foundPos - pos);

        // Then, add s2 (the replacement string) instead of s1
        result += this->s2;

        // Move position past the found s1
        // We skip s1.length() characters to continue searching after it
        pos = foundPos + this->s1.length();
    }

    // Return the modified string
    return result;
}

// writeFile: writes the result to a new file named "filename.replace"
// Returns true on success, false on failure
bool FileReplacer::writeFile(std::string result)
{
    // Create the output filename by appending ".replace"
    std::string outputFilename = this->filename + ".replace";

    // Open the output file for writing
    std::ofstream outputFile(outputFilename.c_str());

    // Check if the file opened successfully
    if (!outputFile.is_open())
    {
        // Print error message
        std::cerr << "Error: Cannot create file '" << outputFilename << "'" << std::endl;
        return false;  // Return false to indicate failure
    }

    // Write the result to the file
    // The << operator writes to the file stream
    outputFile << result;

    // Close the output file
    outputFile.close();

    // Print success message
    std::cout << "File processed successfully!" << std::endl;
    std::cout << "Output written to: " << outputFilename << std::endl;

    // Return true to indicate success
    return true;
}

// process: main function that orchestrates the entire replacement process
// Returns true if all steps succeed, false if any step fails
bool FileReplacer::process(void)
{
    // Step 1: Validate that s1 is not empty
    // (You can't replace an empty string!)
    if (this->s1.empty())
    {
        std::cerr << "Error: Search string (s1) cannot be empty" << std::endl;
        return false;
    }

    // Step 2: Read the input file
    // If reading fails, readFile() will print an error and return false
    if (!this->readFile())
        return false;

    // Step 3: Perform the replacement
    // This creates a new string with all occurrences of s1 replaced by s2
    std::string result = this->replaceAll();

    // Step 4: Write the result to the output file
    // If writing fails, writeFile() will print an error and return false
    if (!this->writeFile(result))
        return false;

    // All steps succeeded!
    return true;
}

