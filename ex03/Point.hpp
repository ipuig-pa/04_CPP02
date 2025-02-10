/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:16:08 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/10 17:54:53 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define PONT_HPP
# include "Fixed.hpp"

class Point{

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point(void);
	int			getX() const;
	int			getY() const;

private:
	const Fixed	_x;
	const Fixed	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif