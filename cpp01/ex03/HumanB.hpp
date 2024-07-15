/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:08:21 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/15 16:10:05 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon& weapon);
};

#endif