/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/06/17 14:43:19 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount;
		int		oldestIndex;

	public:
		PhoneBook();
		int		getFreeIndex();
		int		askForIndex();
		void	addContact();
		int		displayAllContacts();
		void	displayContact(int index);
};

#endif