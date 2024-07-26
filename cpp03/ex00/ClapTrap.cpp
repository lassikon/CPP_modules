/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:14:44 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/26 17:45:36 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :  _name("NoName"), _hitPoints(10),
                    _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  _name(name), _hitPoints(10),
                     _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap&  ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{

}
void    ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes "
            << amount << " points of damage!" << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " gained " << amount
                << "hit points from repairing itself" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name
                << " doesn't have enough energy to repair itself" << std::endl;
    }
}