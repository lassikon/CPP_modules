/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:02:10 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/30 16:57:52 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(),
	_name("NoName_clap_name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
    _energyPoints = 50;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name), _name(name)
{
    _energyPoints = 50;
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " has been destroyed" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap " << _name
        << " copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
		_name = other._name;
    }
    return (*this);
}

void    DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "name: " << _name << ", ClapTrap name: "
		<< ClapTrap::_name << std::endl;
}