/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:57:04 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/05 13:41:05 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdea(other.brain->getIdea(i), i);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		for (int i = 0; i < 100; i++)
			brain->setIdea(other.brain->getIdea(i), i);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << type << ": *barks*" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (brain);
}