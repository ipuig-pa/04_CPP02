/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:16:20 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/11 10:36:54 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	: _x(0), _y(0)
{
}

Point::Point(const float x, const float y)
	: _x(x), _y(y)
{
}

Point::Point(const Point &other)
	: _x(other._x), _y(other._y)
{
	*this = other;
}
// Since _x and _y are const, they cannot be modified after initialization
// This operator exists only to fulfill Orthodox Canonical Form requirements
Point &Point::operator=(const Point &other)
{
	(void)other;
	return(*this);
}

Point::~Point(void)
{
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
