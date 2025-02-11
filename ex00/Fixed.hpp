/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:56:33 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/11 10:47:10 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>

class Fixed{

public:
	Fixed(); //Default constructor
	Fixed(const Fixed &other); //Copy constructor
	Fixed &operator=(const Fixed &other); //Copy assignment operator
	~Fixed(void); //Destructor
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					_value;
	static const int	_fract_bits = 8;

};

#endif