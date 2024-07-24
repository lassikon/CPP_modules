/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:00:11 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/24 12:11:36 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed()
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value)
{
    this->setRawBits(value << this->_fractionalBits);
    std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(const float value)
{
    this->setRawBits(static_cast<int>(roundf(value * 256.0)));
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->setRawBits(other.getRawBits());
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
    return (this->_value);
}

void    Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(this->getRawBits()) / 256.0);
}

int     Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_fractionalBits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
    return (os << fixed.toFloat());
}

// Comparison operators
bool    Fixed::operator>(const Fixed& comparison)
{
    return (this->_value > comparison._value);
}

bool    Fixed::operator<(const Fixed& comparison)
{
    return (this->_value < comparison._value);
}

bool    Fixed::operator>=(const Fixed& comparison)
{
    return (this->_value >= comparison._value);
}

bool    Fixed::operator<=(const Fixed& comparison)
{
    return (this->_value <= comparison._value);
}

bool    Fixed::operator==(const Fixed& comparison)
{
    return (this->_value == comparison._value);
}

bool    Fixed::operator!=(const Fixed& comparison)
{
    return (this->_value != comparison._value);
}

// Arithmetic operators
Fixed   Fixed::operator+(const Fixed& other) const
{
    return (Fixed(this->_value) + other._value);
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    return (Fixed(this->_value) - other._value);
}

Fixed   Fixed::operator*(const Fixed& other) const
{
    return (Fixed(this->_value) * other._value);
}
Fixed   Fixed::operator/(const Fixed& other) const
{
    return (Fixed(this->_value) / other._value);
}

// Increment/decrement operators
