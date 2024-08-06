/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:05:23 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/05 13:30:57 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	brain;

	public:
		Cat();
		Cat(const Cat& other);
		~Cat() override;
		
		Cat&	operator=(const Cat& other);

		void	makeSound() const override;
		Brain*	getBrain() const;
};

#endif