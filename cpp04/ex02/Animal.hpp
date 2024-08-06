/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:26:34 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/06 15:55:50 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal() = 0;

		Animal&	operator=(const Animal& other);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

#endif