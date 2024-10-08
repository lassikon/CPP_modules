/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:15:33 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/26 12:27:55 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

static void	check_point(Point const a, Point const b, Point const c, \
				Point const p, const std::string& name)
{
	if (bsp(a, b, c, p))
		std::cout << "Point " << name << " is inside the triangle" << std::endl;
	else
		std::cout << "Point " << name << " is outside the triangle" << std::endl;
}

int main()
{
	Point	a(0.0f, 0.0f);
	Point	b(5.5f, 0.0f);
	Point	c(0.0f, 5.5f);
	Point	p1(2.2f, 2.2f); // inside the triangle
	Point	p2(5.5f, 5.5f); // outside the triangle
	Point	p3(1.0f, 1.0f); // inside the triangle
	Point	p4(3.5f, 0.0f); // on edge, outside the triangle
	Point	p5(5.5f, 0.0f); // on vertice, outside the triangle
	Point	p6(0.0f, 2.2f); // on edge, outside the triangle

	check_point(a, b, c, p1, "p1");
	check_point(a, b, c, p2, "p2");
	check_point(a, b, c, p3, "p3");
	check_point(a, b, c, p4, "p4");
	check_point(a, b, c, p5, "p5");
	check_point(a, b, c, p6, "p6");

	Point	a2(0.0f, 0.0f);
	Point	b2(2.0f, 0.0f);
	Point	c2(0.0f, 2.0f);
	Point	p7(1.0f, 1.0f); // on edge, outside the triangle
	Point	p8(1.001f, 1.0f); // outside the triangle
	Point	p9(0.99f, 1.0f); // inside the triangle

	check_point(a2, b2, c2, p7, "p7");
	check_point(a2, b2, c2, p8, "p8");
	check_point(a2, b2, c2, p9, "p9");

	return (0);
}