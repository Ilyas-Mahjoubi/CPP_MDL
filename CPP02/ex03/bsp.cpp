/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:16:52 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/22 18:33:43 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(const Point a, const Point b, const Point c)
{
    return std::abs((a.getX()*(b.getY()-c.getY())) + b.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-b.getY()))/2.0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float a0 = area(a, b, c);
	float a1 = area(point, b, c);
	float a2 = area(point, a, c);
	float a3 = area(point, a, b);
	
	if (a1 == 0 || a2 == 0 || a3 == 0)
		return false;
	return (a0 == a1 + a2 + a3);
}
