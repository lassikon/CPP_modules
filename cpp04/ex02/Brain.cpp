/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:07:11 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/05 13:24:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(std::string idea, int index)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	else
		return ("");
}