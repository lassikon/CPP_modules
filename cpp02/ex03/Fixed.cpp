/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:00:11 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/26 12:17:42 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed()
{
    this->setRawBits(0);
    // std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value)
{
    this->setRawBits(value << this->_fractionalBits);
    // std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(const float value)
{
    this->setRawBits(static_cast<int>(roundf(value * (1 << this->_fractionalBits))));
    // std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
    this->setRawBits(other.getRawBits());
    // std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->setRawBits(other.getRawBits());
        // std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
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
    return (static_cast<float>(this->getRawBits()) / (1 << this->_fractionalBits));
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
    Fixed   newNumber;

    newNumber._value = this->_value + other._value;
    return (newNumber);
}

Fixed   Fixed::operator-(const Fixed& other) const
{
    Fixed   newNumber;

    newNumber._value = this->_value - other._value;
    return (newNumber);
}

Fixed   Fixed::operator*(const Fixed& other) const
{
    Fixed   newNumber;
    long long   longValue = static_cast<long long>(this->_value);
    long long   otherLongValue = static_cast<long long>(other._value);

    newNumber._value = static_cast<int>(longValue * otherLongValue) >> this->_fractionalBits;
    return (newNumber);
}

Fixed   Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0)
    {
        std::cout << "Cannot divide by ";
        return (0);
    }
    Fixed   newNumber;
    long long   longValue = static_cast<long long>(this->_value);

    newNumber._value = static_cast<int>((longValue << this->_fractionalBits) / other._value);
    return (newNumber);
}

// Pre-increment
Fixed&  Fixed::operator++(void)
{
    ++_value;
    return (*this);
}

// Post-increment
Fixed  Fixed::operator++(int)
{
    Fixed   temp = *this;
    ++_value;
    return (temp);
}

// Pre-decrement
Fixed&  Fixed::operator--(void)
{
    --_value;
    return (*this);
}

// Post-decrement
Fixed  Fixed::operator--(int)
{
    Fixed   temp = *this;
    --_value;
    return (temp);
}

// Overloaded min/max functions
Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&    Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&    Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}