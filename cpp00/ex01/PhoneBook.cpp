/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:36 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/19 14:42:42 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
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

void    PhoneBook::promptContactField(int field)
{
    switch (field)
    {
        case 0:
            std::cout << "First Name: ";
            break ;
        case 1:
            std::cout << "Last Name: ";
            break ;
        case 2:
            std::cout << "Nickname: ";
            break ;
        case 3:
            std::cout << "Phone Number: ";
            break ;
        case 4:
            std::cout << "Darkest Secret: ";
            break ;
    }
}

int PhoneBook::addContact()
{
    std::string input;
    int         index = this->getFreeIndex();
    int         field = 0;

    while (field < 5)
    {
        promptContactField(field);
        std::getline(std::cin, input);
        if (std::cin.eof())
            return (EOF);
        else if (input == "")
        {
            std::cout << "A contact can't have empty fields!" << std::endl;
            continue ;
        }
        else
            this->contacts[index].setContactField(input, field);
        field++;
    }
    if (this->contactCount < 8)
        this->contactCount++;
    return (0);
}

int PhoneBook::displayAllContacts()
{
    int i = 0;

    if (this->contactCount == 0)
    {
        std::cout << "No contacts" << std::endl;
        return (1);
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
            << this->truncateString(this->contacts[i].getContactField(0)) << "|";
        std::cout << std::setw(10)
            << this->truncateString(this->contacts[i].getContactField(1)) << "|";
        std::cout << std::setw(10)
            << this->truncateString(this->contacts[i].getContactField(2)) << std::endl;
        i++;
    }
    std::cout << std::endl;
    return (0);
}

int	PhoneBook::askForIndex()
{
	int			index;

    while (true)
    {
        std::cout << "Type index of the contact you want to display: ";
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
        {
            std::cin.ignore(INT_MAX, '\n');
            return (index);
        }
    }
}

void    PhoneBook::displayContact(int index)
{
    std::cout << std::endl;
    std::cout << "Contact information" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        promptContactField(i);
        std::cout << this->contacts[index].getContactField(i) << std::endl;
    }
}
