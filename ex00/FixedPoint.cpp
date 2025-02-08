/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPoint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:59:52 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/06 10:58:59 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
	: _value(0), _fract_bits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = getRawBits();
	// Copy members from other
}

Fixed& operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {  // Protect against self-assignment
		// Clean up existing resources
		// Copy members from other
		this->value = getRawBits();
	}
	return *this;
}

~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
	// Clean up resources
}


int getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
}