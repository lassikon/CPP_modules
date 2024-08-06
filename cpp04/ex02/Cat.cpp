/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:08:21 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/05 13:32:17 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(other.brain->getIdea(i), i);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		for (int i = 0; i < 100; i++)
			brain->setIdea(other.brain->getIdea(i), i);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << type << ": *meows*" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (brain);
}