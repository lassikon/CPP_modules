/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:24:32 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/25 13:40:56 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;
	randomChump("Bar");
	return (0);
}
