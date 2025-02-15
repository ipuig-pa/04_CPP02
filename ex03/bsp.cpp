/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:32:35 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/15 15:09:17 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//returns the expected Y position of point given its X and assumint that it is on the line l1-l2
Fixed	interpolate(Point const a, Point const b, Fixed const x)
{
	Fixed	m;
	Fixed	y;

	m = (b.getY()-a.getY())/(b.getX()-a.getX());
	y = m * x + (a.getY() - (m * a.getX()));
	return (y);
}

//check if the point falls at the same side of the line l1-l2 than the third vertex (v).
bool	check_same_side(Point const l1, Point const l2, Point const v, Point const point)
{
	Fixed	p_edge_y;
	Fixed	v_edge_y;

	if (l1.getX() != l2.getX())
	{
		p_edge_y = interpolate(l1, l2, point.getX());
		v_edge_y = interpolate(l1, l2, v.getX());
		if (v.getY() > v_edge_y)
		{
			if (point.getY() > p_edge_y)
				return (true);
		}
		else if (point.getY() < p_edge_y)
			return (true);
	}
	else
	{
		if (v.getX() > l1.getX())
		{
			if (point.getX() > l1.getX())
				return (true);
		}
		else if (point.getX() < l1.getX())
			return (true);
	}
	return (false);
}

//returns true if the point is inside the triangle
//checks that the point falls at the same side of the line created by two vertices as the third vertex (done for all 3 combinations)
bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (check_same_side(a, b, c, point))
	{
		if (check_same_side(b, c, a, point))
			return (check_same_side(c, a, b, point));
	}
	return (false);
}
