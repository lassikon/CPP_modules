/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:12:34 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/30 16:51:09 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap red("Red");
	DiamondTrap blue("Blue");
	DiamondTrap green("Green");
	std::cout << std::endl;

	red.attack("Blue");
	blue.beRepaired(5);
	blue.takeDamage(10);
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		blue.beRepaired(5);
	std::cout << std::endl;

	blue.attack("Red");
	red.takeDamage(10);
	red.beRepaired(5);
	std::cout << std::endl;
	
	red.attack("Green");
	green.takeDamage(200);
	green.takeDamage(200);
	green.beRepaired(5);
	green.attack("Red");
	std::cout << std::endl;

	green.whoAmI();
	blue.whoAmI();
	std::cout << std::endl;

	red = green;
	std::cout << std::endl;

	return (0);
}