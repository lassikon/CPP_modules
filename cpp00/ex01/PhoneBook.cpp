/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:36 by lkonttin          #+#    #+#             */
/*   Updated: 2024/06/06 11:06:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::addContact(int index)
{
    std::string input;

    std::cout << "first name: ";
    std::getline(std::cin, input);
    this->contacts[index].setFirstName(input);

    std::cout << "last name: ";
    std::getline(std::cin, input);
    this->contacts[index].setLastName(input);

    std::cout << "nickname: ";
    std::getline(std::cin, input);
    this->contacts[index].setNickname(input);

    std::cout << "phone number: ";
    std::getline(std::cin, input);
    this->contacts[index].setPhoneNumber(input);

    std::cout << "darkest secret: ";
    std::getline(std::cin, input);
    this->contacts[index].setDarkestSecret(input);
}

void    PhoneBook::displayContact(int index)
{
    std::cout << this->contacts[index].getFirstName() << std::endl;
    std::cout << this->contacts[index].getLastName() << std::endl;
    std::cout << this->contacts[index].getNickname() << std::endl;
    std::cout << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << this->contacts[index].getDarkestSecret() << std::endl;
}
