/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:59:52 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/15 14:46:33 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
	: _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = value << _fract_bits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed &other) 
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed() 
{
	//std::cout << "Destructor called" << std::endl;
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
	return (static_cast<float>(this->_value) / static_cast<float>(1 << _fract_bits));
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

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result._value = this->_value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	result._value = this->_value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	result._value = (this->_value * other._value) >> _fract_bits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	if (other._value == 0)
		std::cout << "Error: division by 0, result will be set to 0" << std::endl;
	else
		result._value = (this->_value << _fract_bits) / other._value;
	return (result);
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return(*this);
}

// Post-increment
Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp = *this;
	this->_value++;
	return(temp);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return(*this);
}

// Post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp = *this;
	this->_value--;
	return(temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value<b._value)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value<b._value)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value>b._value)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value>b._value)
		return (a);
	return (b);
}
