/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:32:25 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/26 12:34:57 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

static float	area(Point const a, Point const b, Point const c)
{
	Fixed	area = (a.getX() * (b.getY() - c.getY()) + b.getX() \
                * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	if (area < 0)
		return (area.toFloat() * -1);
	else
		return (area.toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	totalArea = area(a, b, c);
	float	area1 = area(point, a, b);
	float	area2 = area(point, b, c);
	float	area3 = area(point, c, a);

	if (area1 == 0.0f || area2 == 0.0f || area3 == 0.0f)
		return (false);

	float	result = totalArea - (area1 + area2 + area3);
	if (result < 0)
		result *= -1;

	if (result < 0.01)
		return (true);
	else
		return (false);
}