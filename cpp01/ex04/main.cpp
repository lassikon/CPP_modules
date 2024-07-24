/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:17:11 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/24 14:47:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return (1);
    }
    else
    {
        Replacer replacer(argv[1], argv[2], argv[3]);
        if (replacer.replace())
            return (1);
    }
    return (0);
}