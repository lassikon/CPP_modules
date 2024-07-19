/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/19 11:53:35 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact		contacts[MAX_CONTACTS];
		int			contactCount;
		int			oldestIndex;
		int			getFreeIndex();
		int			addContactField(int index, int field);
		std::string	truncateString(std::string str);

	public:
		PhoneBook();
		int		askForIndex();
		int		addContact();
		int		displayAllContacts();
		void	displayContact(int index);
};

#endif