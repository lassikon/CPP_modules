/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:06:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/06/18 17:33:41 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact		contacts[MAX_CONTACTS];
		int			contactCount;
		int			oldestIndex;
		int			getFreeIndex();
		std::string	truncateString(std::string str);

	public:
		PhoneBook();
		int		askForIndex();
		void	addContact();
		int		displayAllContacts();
		void	displayContact(int index);
};

#endif