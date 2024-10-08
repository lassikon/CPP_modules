/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:07:41 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/23 12:10:19 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
