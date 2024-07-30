/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:46:16 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/30 15:59:37 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
	_hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap " << _name
        << " copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
        std::cout << "ScavTrap " << _name << " can't attack because it's dead";
    else if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name
            << " doesn't have enough energy to attack " << target; 
    }
    else
    {
        std::cout << "ScavTrap " << _name << " attacks " << target
            << ", causing " << _attackDamage << " points of damage";
        _energyPoints--;
    }
    std::cout << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_hitPoints < 1)
	{
		std::cout << "ScavTrap " << _name << " can't guard because it's dead";
	}
	else
	{
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode";
	}
	std::cout << std::endl;
}