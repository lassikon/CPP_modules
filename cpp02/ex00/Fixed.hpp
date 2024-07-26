/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:00:08 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/26 11:23:23 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8; 

    public:
        Fixed();
        Fixed(const Fixed& other);
        ~Fixed();
        
        Fixed& operator=(const Fixed& other);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif