/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:47:58 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/17 11:50:08 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string filename, std::string s1,  std::string s2)
    : filename(filename), s1(s1), s2(s2)
{
    return ;
}

std::string Replacer::readFile()
{
    std::ifstream inFile(filename);
    std::string content;

    inFile >> content;
    
    return (content);
}

int Replacer::writeFile(std::string content)
{
    std::ofstream outFile(filename + ".replace");
    if (!outFile)
        return (1);
    outFile << content;
    return (0);
}

int Replacer::replace()
{
    std::string content = readFile();
    if (content.empty())
        return (1);
    writeFile(content);
    return (0);
}
