/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:32:54 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/29 18:35:49 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>


class Fixed
{
	private:
		int	rawbits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int param);
		Fixed(const float floatparam);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed& obj);
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
