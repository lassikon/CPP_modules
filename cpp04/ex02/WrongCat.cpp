/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:52:29 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/05 12:53:25 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << type << ": *meows*" << std::endl;
}