/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:59:53 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/13 12:33:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("Default")
{
    // std::cout << "AMateria default constructor called for type: " << _type << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    // std::cout << "AMateria constructor called for type: " << _type << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    // std::cout << "AMateria copy constructor called for type: " << _type << std::endl;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor called for type: " << _type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    (void)other;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (_type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << " uses AMateria " << _type << std::endl;
}