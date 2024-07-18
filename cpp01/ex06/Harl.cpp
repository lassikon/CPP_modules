/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:03:31 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/18 15:21:30 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout   << "[ DEBUG ]" << std::endl
                << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
                << "I really do!"
                << std::endl << std::endl;
}

void    Harl::info(void)
{
    std::cout   << "[ INFO ]" << std::endl
                << "I cannot believe adding extra bacon costs more money. "
                << "You didn't put enough bacon in my burger! "
                << "If you did, I wouldn't be asking for more!"
                << std::endl << std::endl;
}

void    Harl::warning(void)
{
    std::cout   << "[ WARNING ]" << std::endl
                << "I think I deserve to have some extra bacon for free. "
                << "I've been coming for years whereas you started working here since last month."
                << std::endl << std::endl;
}

void    Harl::error(void)
{
    std::cout   << "[ ERROR ]" << std::endl
                << "This is unacceptable! I want to speak to the manager now."
                << std::endl << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    
    while (i < 4)
    {
        if (!levels[i].compare(level))
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            Harl::debug();
        case 1:
            Harl::info();
        case 2:
            Harl::warning();
        case 3:
            Harl::error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
    }
}
