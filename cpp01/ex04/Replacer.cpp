/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:58 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/24 14:47:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1,  std::string s2)
    : filename(filename), s1(s1), s2(s2) {}

void    Replacer::printError(std::string message)
{
    std::cout << "Error: " << message << std::endl;
    return ;
}

std::string Replacer::readFile()
{
    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        printError("Could not open the file");
        return ("");
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
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
    if (s1 == "")
    {
        printError("string1 cannot be empty");
        return (1);
    }
    std::string content = readFile();
    if (content.empty())
        return (1);
    std::string newContent;
    size_t      pos = 0;
    size_t      foundPos;
    while (true)
    {
        foundPos = content.find(s1, pos);
        if (foundPos == std::string::npos)
            break ;
        newContent.append(content, pos, foundPos - pos);
        newContent += s2;
        pos = foundPos + s1.length();
    }
    newContent.append(content, pos, std::string::npos);
    if (writeFile(newContent))
        return (1);
    return (0);
}
