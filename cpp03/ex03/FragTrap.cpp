/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:41:15 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/08 11:04:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _name = "NoName";
	std::cout << "FragTrap " << _name << " default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap " << _name
        << " copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

void    FragTrap::attack(const std::string& target)
{
    if (_hitPoints < 1)
        std::cout << "FragTrap " << _name << " can't attack because it's dead";
    else if (_energyPoints > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target
            << ", causing " << _attackDamage << " points of damage";
        _energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << _name
            << " doesn't have enough energy to attack " << target;
    }
    std::cout << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (_hitPoints < 1)
	{
		std::cout << "FragTrap " << _name << " can't high five because it's dead";
	}
	else
	{
		std::cout << "FragTrap " << _name << " requests a high five";
	}
	std::cout << std::endl;
}