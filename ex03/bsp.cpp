/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:32:35 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/10 17:55:38 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	interpolate(Point const a, Point const b, Fixed const x)
{
	Fixed	y;

	y = ((b.getY()-a.getY())/(b.getX()-a.getX())) * x + (a.getY - (((b.getY()-a.getY())/(b.getX()-a.getX())) * a.getX()));
	return (y);
}

bool	check_same_side(Point const l1, Point const l2, Point const v, Point const point)
{
	Fixed	edge_y;

	edge_y = interpolate(l1, l2, point.getX());
	if (v.getY() > edge_y)
	{
		if (point.getY() > edge_y)
			return (true);
	}
	else if (point.getY() < edge_y)
		return (true);
	return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (check_same_side(a, b, c, point))
	{
		if (check_same_side(b, c, a, point))
			return (check_same_side(c, a, b, point))
	}
	return (false);
}
