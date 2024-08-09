/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:20:25 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/09 16:50:18 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_memory[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource() override;

		MateriaSource&	operator=(const MateriaSource& other);

		void		learnMateria(AMateria*) override;
		AMateria*	createMateria(std::string const & type) override;
};

#endif