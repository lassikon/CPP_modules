/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:15:33 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/25 11:25:43 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    
    std::cout << "Testing comparisson operators:" << std::endl;

	std::cout << "Is more?" << std::endl;
	Fixed n1 = Fixed(1.0f);
	n1++;
	Fixed n2 = Fixed(1.0f);
	std::cout << n1 << " > " << n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 > n2) << std::endl;
	std::cout << n1 << " > " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 > n2) << std::endl;
	std::cout << n1 << " > " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 > n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Is less?" << std::endl;
	n1 = Fixed(2.0f);
	n1++;
	n2 = Fixed(2.0f);
	std::cout << n1 << " < " << n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 < n2) << std::endl;
	std::cout << n1 << " < " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 < n2) << std::endl;
	std::cout << n1 << " < " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 < n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Is more or equal?" << std::endl;
	n1 = Fixed(2.0f);
	n1++;
	n2 = Fixed(2.0f);
	std::cout << n1 << " >= " << n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 >= n2) << std::endl;
	std::cout << n1 << " >= " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 >= n2) << std::endl;
	std::cout << n1 << " >= " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 >= n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Is less or equal?" << std::endl;
	n1 = Fixed(2.0f);
	n1++;
	n2 = Fixed(2.0f);
	std::cout << n1 << " <= " << n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 <= n2) << std::endl;
	std::cout << n1 << " <= " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 <= n2) << std::endl;
	std::cout << n1 << " <= " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 <= n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Are equal?" << std::endl;
	n1 = Fixed(1.0f);
	n1++;
	n2 = Fixed(1.0f);
	std::cout << n1 << " == " << n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 == n2) << std::endl;
	std::cout << n1 << " == " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 == n2) << std::endl;
	std::cout << n1 << " == " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 == n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Are not equal?" << std::endl;
	n1 = Fixed(1.0f);
	n1++;
	n2 = Fixed(1.0f);
	std::cout << n1 << " != " << n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 != n2) << std::endl;
	std::cout << n1 << " != " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 != n2) << std::endl;
	std::cout << n1 << " != " << ++n2 << std::endl;
	std::cout <<  std::boolalpha << (n1 != n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Testing arithmetic operators:" << std::endl;
	n1 = Fixed(15.0f);
	n2 = Fixed(3.0f);
	std::cout << n1 << " + " << n2 << " = "<< n1 + n2 << std::endl;
	std::cout << n1 << " - " << n2 << " = "<< n1 - n2 << std::endl;
	std::cout << n1 << " / " << n2 << " = "<< n1 / n2 << std::endl;
	std::cout << n1 << " * " << n2 << " = "<< n1 * n2 << std::endl;
	n1 = Fixed(14.4f);
	n2 = Fixed(0.3f);
	std::cout << n1 << " + " << n2 << " = "<< n1 + n2 << std::endl;
	std::cout << n1 << " - " << n2 << " = "<< n1 - n2 << std::endl;
	std::cout << n1 << " / " << n2 << " = "<< n1 / n2 << std::endl;
	std::cout << n1 << " * " << n2 << " = "<< n1 * n2 << std::endl;
    n2 = Fixed(0.0f);
    std::cout << "Division by zero" << std::endl;
    std::cout << n1 << " / " << n2 << " = "<< n1 / n2 << std::endl;
	std::cout << std::endl;

	std::cout << "Testing increment/decrement operators:" << std::endl;

	n1 = Fixed(1.0f);
	std::cout << n1 << std::endl;
	std::cout << --n1 << " <<--- pre-decrement"<< std::endl;
	std::cout << n1 << std::endl;
	std::cout << std::endl;

	n1 = Fixed(1.0f);
	std::cout << n1 << std::endl;
	std::cout << n1-- << " <<--- post-decrement"<< std::endl;
	std::cout << n1 << std::endl;
	std::cout << std::endl;

	n1 = Fixed(1.0f);
	std::cout << n1 << std::endl;
	std::cout << ++n1 << " <<--- pre-increment"<< std::endl;
	std::cout << n1 << std::endl;
	std::cout << std::endl;

	n1 = Fixed(1.0f);
	std::cout << n1 << std::endl;
	std::cout << n1++ << " <<--- post-increment"<< std::endl;
	std::cout << n1 << std::endl;
	std::cout << std::endl;

	std::cout << "Testing min/max operators:" << std::endl;
	n1 = Fixed(1.0f);
	n2 = Fixed(1.0f);

	std::cout << "Min?" << std::endl;
	n1 = Fixed(1.0f);
	n2 = Fixed(1.0f);
	std::cout << n1 << " between " << n2 << std::endl;
	std::cout << Fixed::min(n1, n2) << std::endl;
	n1++;
	std::cout << n1 << " between " << n2 << std::endl;
	std::cout << Fixed::min(n1, n2) << std::endl;
	n2++;
	n2++;
	std::cout << n1 << " between " << n2 << std::endl;
	std::cout << Fixed::min(n1, n2) << std::endl;
	std::cout << std::endl;

	std::cout << "Max?" << std::endl;
	n1 = Fixed(1.0f);
	n2 = Fixed(1.0f);
	std::cout << n1 << " between " << n2 << std::endl;
	std::cout << Fixed::max(n1, n2) << std::endl;
	n1++;
	std::cout << n1 << " between " << n2 << std::endl;
	std::cout << Fixed::max(n1, n2) << std::endl;
	n2++;
	n2++;
	std::cout << n1 << " between " << n2 << std::endl;
	std::cout << Fixed::max(n1, n2) << std::endl;
	std::cout << std::endl;

	return 0;
}