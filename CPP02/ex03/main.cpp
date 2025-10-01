/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:32:52 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/01 17:40:56 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 2.0f);
	Point c(1.0f, 7.0f);
	Point p(3.0f, 3.0f);
	if (bsp(a, b, c, p))
		std::cout <<"Inside" << std::endl;
	else
		std::cout <<"Not Inside" << std::endl;
	return 0;
}
