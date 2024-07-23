/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:11:07 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/23 11:42:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void) const;
};

Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);

#endif
