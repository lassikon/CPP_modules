/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:00:08 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/24 12:11:36 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8; 

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

        // Comparison operators
        bool    operator>(const Fixed& comparison);
        bool    operator<(const Fixed& comparison);
        bool    operator>=(const Fixed& comparison);
        bool    operator<=(const Fixed& comparison);
        bool    operator==(const Fixed& comparison);
        bool    operator!=(const Fixed& comparison);

        // Arithmetic operators
        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif