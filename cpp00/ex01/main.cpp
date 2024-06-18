/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:07:00 by lkonttin          #+#    #+#             */
/*   Updated: 2024/06/18 17:32:02 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	std::string	input;
	PhoneBook	phoneBook;
	int			index;

	while (true)
	{
		std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			break ;
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
		{
			if (phoneBook.displayAllContacts())
			{
				index = phoneBook.askForIndex();
				if (index == EOF)
					break ;
				phoneBook.displayContact(index);
			}
		}
		else
			std::cout << "Error: Invalid command" << std::endl;
	}
	return (0);
}
