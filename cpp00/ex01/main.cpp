/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:07:00 by lkonttin          #+#    #+#             */
/*   Updated: 2024/06/11 12:18:00 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	(void)phonebook;
	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			//add contact
		}
		else if (input == "SEARCH")
		{
			//search
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
