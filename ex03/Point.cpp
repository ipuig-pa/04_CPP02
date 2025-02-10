/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:16:20 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/10 17:56:01 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	_x(0), _y(0)
{
}

Point::Point(const float x, const float y)
	_x(x), _y(y)
{
}

Point::Point(const Point &other)
{
	*this = other;
}
Point &operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return(*this);
}

~Point(void)
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
