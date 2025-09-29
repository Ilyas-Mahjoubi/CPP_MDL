/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:32:49 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/29 18:57:15 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->rawbits = 0;
}

Fixed::Fixed(const int param)
{
	std::cout << "Int constructor called" << std::endl;
	rawbits = param << fractionalBits;
}
Fixed::Fixed(const float floatparam)
{
	std::cout << "Float constructor called" << std::endl;
	rawbits = roundf(floatparam * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(obj);
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->rawbits = obj.rawbits;
	return *this;
}

float Fixed::toFloat( void ) const
{
	return (float)rawbits / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
	return rawbits >> fractionalBits;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawbits;
}

void Fixed::setRawBits( int const raw )
{
	this->rawbits = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
