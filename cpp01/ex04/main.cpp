/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:17:11 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/17 11:50:08 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        return (1);
    }
    else
    {
        Replacer replacer(argv[1], argv[2], argv[3]);
        replacer.replace();
    }
    return (0);
}