/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:46 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/22 11:40:12 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
    return ;
}

void	Contact::setContactField(std::string input, int field)
{
    switch (field)
    {
        case 0:
            this->firstName = input;
            break ;
        case 1:
            this->lastName = input;
            break ;
        case 2:
            this->nickname = input;
            break ;
        case 3:
            this->phoneNumber = input;
            break ;
        case 4:
            this->darkestSecret = input;
            break ;
    }
}

std::string Contact::getContactField(int field)
{
    switch (field)
    {
        case 0:
            return (this->firstName);
        case 1:
            return (this->lastName);
        case 2:
            return (this->nickname);
        case 3:
            return (this->phoneNumber);
        case 4:
            return (this->darkestSecret);
        default:
            return ("");
    }
}
