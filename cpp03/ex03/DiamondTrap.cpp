/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:02:10 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/08 11:37:03 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(),
	_name("NoName_clap_name")
{
    _energyPoints = 50;
	std::cout << "DiamondTrap " << _name << " default constructor called" << std::endl;
	std::cout << _name << ": Hit points = " << _hitPoints << std::endl;
	std::cout << _name << ": Energy points = " << _energyPoints << std::endl;
	std::cout << _name << ": Attack damage = " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name), _name(name)
{
    _energyPoints = 50;
	std::cout << "DiamondTrap " << _name << " has been created" << std::endl;
	std::cout << _name << ": Hit points = " << _hitPoints << std::endl;
	std::cout << _name << ": Energy points = " << _energyPoints << std::endl;
	std::cout << _name << ": Attack damage = " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other), _name(other._name)
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