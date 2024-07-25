/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:32:25 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/25 12:48:59 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

Fixed sign(Point const p, Point const a, Point const b)
{
    Fixed   px = p.getX();
    Fixed   py = p.getY();
    Fixed   ax = a.getX();
    Fixed   ay = a.getY();
    Fixed   bx = b.getX();
    Fixed   by = b.getY();

    return ((px - bx) * (ay - by) - (ax - bx) * (py - by));
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return (!(has_neg && has_pos));
}

// ax = 0, ay = 4
// bx = 4, by = 0
// cx = 0, xy = 0

// px = 1, py = 1

// sign ab
// (1 - 4) * (4 - 0) - (0 - 4) * (1 - 0) = -12 - -4 = -8

// sign bc
// (1 - 0) * (0 - 0) - (4 - 0) * (1 - 0) = -3