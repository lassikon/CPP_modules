/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:54:14 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/05 13:38:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain;

	public:
		Dog();
		Dog(const Dog& other);
		~Dog() override;

		Dog&	operator=(const Dog& other);

		void	makeSound() const override;
		Brain*	getBrain() const;
};

#endif