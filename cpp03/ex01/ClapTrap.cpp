/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:14:44 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/08 10:59:17 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name("NoName"), _hitPoints(10),
                    _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :  _name(name), _hitPoints(10),
                     _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name),
     _hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
     _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap&  ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap " << _name
        << " copy assignment operator called" << std::endl;
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
    if (_hitPoints == 0)
        std::cout << "Claptrap " << _name << " can't attack because it's dead";
    else if (_energyPoints == 0)
    {
        std::cout << "Claptrap " << _name
            << " doesn't have enough energy to attack " << target; 
    }
    else
    {
        std::cout << "Claptrap " << _name << " attacks " << target
            << ", causing " << _attackDamage << " points of damage";
        _energyPoints--;
    }
    std::cout << std::endl;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes "
            << amount << " points of damage";
    if (_hitPoints == 0)
    {
        std::cout << ", but it was already dead anyway";
    }
    else if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << " and dies";
    }
    else
    {
        _hitPoints -= amount;
        std::cout << " and has " << _hitPoints << " hp left";
    }
    std::cout << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name
            << " can't repair itself because it's dead";
    }
    else if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name
            << " doesn't have enough energy to repair itself";
    }
    else
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount
                << " hp and has a total of " << _hitPoints << " hp";
    }
    std::cout << std::endl;
}