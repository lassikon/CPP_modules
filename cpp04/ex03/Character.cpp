/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:58:32 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/09 11:15:46 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name)
{
	// copy inventory
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character&	Character::operator=(const Character& other)
{
	// deep copy, delete old inventory
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
	}
}
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = nullptr;
}
void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx] != nullptr)
		_inventory[idx]->use(target);
}
AMateria*	Character::getInventory(int idx) const
{
	if (idx >= 0 && idx <= 3)
		return (_inventory[idx]);
	else
		return (nullptr);
}