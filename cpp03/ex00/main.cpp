/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:12:34 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/27 12:14:35 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{

    ClapTrap claptrap("clapper");
	claptrap.attack("goblin");
	claptrap.attack("goblin");
	claptrap.takeDamage(8);
	claptrap.beRepaired(8);
	claptrap.attack("goblin");
	claptrap.takeDamage(8);
	claptrap.beRepaired(8);
	claptrap.takeDamage(8);
	claptrap.attack("goblin");
	claptrap.beRepaired(90);
	claptrap.takeDamage(100);
	claptrap.attack("goblin");
	claptrap.beRepaired(100);
}