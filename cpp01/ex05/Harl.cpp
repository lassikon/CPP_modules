/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:03:31 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/18 12:27:01 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout   << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
                << "I really do!"
                << std::endl;
}

void    Harl::info(void)
{
    std::cout   << "I cannot believe adding extra bacon costs more money. "
                << "You didn't put enough bacon in my burger! "
                << "If you did, I wouldn't be asking for more!"
                << std::endl;
}

void    Harl::warning(void)
{
    std::cout   << "I think I deserve to have some extra bacon for free. "
                << "I've been coming for years whereas you started working here since last month."
                << std::endl;
}

void    Harl::error(void)
{
    std::cout   << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    MemberFunction functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; ++i)
    {
        if (!levels[i].compare(level))
        {
            (this->*functions[i])();
            return ;
        }
    }
    std::cout << "Error: " << level << " is not a valid level" << std::endl;
}
