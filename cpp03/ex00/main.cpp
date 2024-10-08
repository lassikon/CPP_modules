/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:12:34 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/08 10:48:05 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap red("Red");
	ClapTrap blue("Blue");
	ClapTrap green("Green");
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
	green.takeDamage(10);
	green.takeDamage(10);
	green.beRepaired(5);
	green.attack("Red");
	std::cout << std::endl;

	green = red;
	green.attack("Red");

	return (0);
}