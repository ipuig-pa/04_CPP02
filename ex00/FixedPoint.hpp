/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:56:33 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/05 13:38:43 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FXDPNT_HPP
# define FXDPNT_HPP
# include <string>
# include <iostream>

class FixedPoint{

public:
	FixedPoint();

	
	~FixedPoint(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					value;
	static const int	fract_bits;

};

#endif