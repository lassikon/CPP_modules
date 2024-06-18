/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:36 by lkonttin          #+#    #+#             */
/*   Updated: 2024/06/18 17:31:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contactCount = 0;
    this->oldestIndex = 0;
    return ;
}

std::string PhoneBook::truncateString(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

int PhoneBook::getFreeIndex()
{
    int i = 0;

    if (this->contactCount < 8)
        return (this->contactCount);
    i = this->oldestIndex;
    this->oldestIndex++;
    if (this->oldestIndex == 8)
        this->oldestIndex = 0;
    return (i);
}

void    PhoneBook::addContact()
{
    std::string input;
    int         index;

    index = this->getFreeIndex();

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    this->contacts[index].setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    this->contacts[index].setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    this->contacts[index].setNickname(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    this->contacts[index].setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    this->contacts[index].setDarkestSecret(input);

    if (this->contactCount < 8)
        this->contactCount++;
}

int PhoneBook::displayAllContacts()
{
    int i = 0;

    if (this->contactCount == 0)
    {
        std::cout << "No contacts" << std::endl;
        return (0);
    }
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "     --------------------------------------" << std::endl;
    while (i < this->contactCount)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10)
            << this->truncateString(this->contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10)
            << this->truncateString(this->contacts[i].getLastName()) << "|";
        std::cout << std::setw(10)
            << this->truncateString(this->contacts[i].getNickname()) << std::endl;
        i++;
    }
    return (1);
}

int	PhoneBook::askForIndex()
{
	int			index;

    while (true)
    {
        std::cout << "Type index of the contact you want to display" << std::endl;
        std::cin >> index;
        if (std::cin.eof())
            return (EOF);
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Error: Invalid input!" << std::endl;
        }
        else if (index < 0 || index >= this->contactCount)
            std::cout << "Error: No contact for this index!" << std::endl;
        else
            return (index);
    }
}

void    PhoneBook::displayContact(int index)
{
    std::cout << this->contacts[index].getFirstName() << std::endl;
    std::cout << this->contacts[index].getLastName() << std::endl;
    std::cout << this->contacts[index].getNickname() << std::endl;
    std::cout << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << this->contacts[index].getDarkestSecret() << std::endl;
}
