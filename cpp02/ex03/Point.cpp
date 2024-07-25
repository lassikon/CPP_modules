/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:32:36 by lkonttin          #+#    #+#             */
/*   Updated: 2024/07/25 11:53:58 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point&  Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Fixed   Point::getX(void) const
{
    return (this->x);
}

Fixed   Point::getY(void) const
{
    return (this->y);
}