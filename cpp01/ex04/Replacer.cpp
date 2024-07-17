/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:58 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/17 13:12:57 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1,  std::string s2)
    : filename(filename), s1(s1), s2(s2) {}

void    Replacer::printError(std::string errorMessage)
{
    std::cerr << "Error: " << errorMessage << std::endl;
    return ;
}

std::string Replacer::readFile()
{
    std::ifstream inFile(filename);
    std::string content;

    if (!inFile.is_open())
    {
        printError("Could not open the file");
        return ("");
    }
    inFile >> content;
    if (content.empty())
    {
        printError("Failed to read the file, or file is empty");
        return ("");
    }
    return (content);
}

int Replacer::writeFile(std::string content)
{
    std::ofstream outFile(filename + ".replace");
    if (!outFile.is_open())
    {
        printError("Could not create the outfile");
        return (1);
    }
    outFile << content;
    return (0);
}

int Replacer::replace()
{
    std::string content = readFile();
    if (content.empty())
        return (1);
    if (writeFile(content))
        return (1);
    return (0);
}
