/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:32:54 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/29 17:45:04 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>


class Fixed
{
	private:
		int	rawbits;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed& obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

#endif
