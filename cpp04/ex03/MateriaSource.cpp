/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:45:01 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/13 12:33:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_memory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._memory[i] != nullptr)
			_memory[i] = other._memory[i]->clone();
		else
			_memory[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != nullptr)
		{
			for (int k = i + 1; k < 4; k++) // to avoid double free
			{
				if (_memory[k] == _memory[i])
					_memory[k] = nullptr;
			}
			delete _memory[i];
			_memory[i] = nullptr;
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _memory[i];
			if (other._memory[i] != nullptr)
				_memory[i] = other._memory[i]->clone();
			else
				_memory[i] = nullptr;
			
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] == nullptr)
		{
			std::cout << "MateriaSource learned " << m->getType() << std::endl;
			_memory[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource memory is full" << std::endl;
	for (int i = 0; i < 4; i ++)
	{
		if (_memory[i] == m)
			return ; // not deleting m if it was in the memory
	}
	delete m;
	m = nullptr;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i] != nullptr && _memory[i]->getType() == type)
		{
			std::cout << "MateriaSource created " << type << std::endl;
			return (_memory[i]->clone());
		}
	}
	std::cout << "Unknown Materia type" << std::endl;
	return (0);
}