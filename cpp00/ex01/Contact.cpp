/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:46 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/19 09:59:10 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

void	Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
    return (this->firstName);
}

std::string	Contact::getLastName()
{
    return (this->lastName);
}

std::string	Contact::getNickname()
{
    return (this->nickname);
}

std::string	Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
    return (this->darkestSecret);
}
