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
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;

	if (value > ((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) - 1)
	{
		std::cout << "Error: this number is too big to be stored as a fixed point, it will be fixed to the max boundary" << std::endl;
		_value = (((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) - 1) << _fract_bits;
	}
	else if (value < ((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) * (-1))
	{
		std::cout << "Error: this number is too small to be stored as a fixed point, it will be fixed to the min boundary" << std::endl;
		_value = (((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) * (-1)) << _fract_bits;
	}
	else
		_value = (value << _fract_bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	if (static_cast<int>(value) > ((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) - 1)
	{
		std::cout << "Error: this number is too big to be stored as a fixed point, it will be fixed to the max boundary" << std::endl;
		_value = (((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) - 1) << _fract_bits;
	}
	else if (static_cast<int>(value) < ((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) * (-1))
	{
		std::cout << "Error: this number is too small to be stored as a fixed point, it will be fixed to the min boundary" << std::endl;
		_value = (((ft_power(2, (static_cast<int>((sizeof(int))*8) - _fract_bits))) / 2) * (-1)) << _fract_bits;
	}
	else
		_value = roundf(value*ft_power(2, _fract_bits));
}

Fixed::Fixed(const Fixed &other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_value / static_cast<float>(ft_power(2, _fract_bits))));
}

int Fixed::toInt( void ) const
{
	return (this->_value >> _fract_bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return(os);
}

int	ft_power(int base, int exp)
{
	int	res;

	res = 1;
	while (exp > 0)
	{
		res = res * base;
		exp --;
	}
	return (res);
}