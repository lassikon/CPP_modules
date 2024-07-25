/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:49 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/25 14:56:09 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "DefaultZombie";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
