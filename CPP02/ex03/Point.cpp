/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:30:47 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/01 16:55:19 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() :x(0) , y(0)
{

}
Point::Point(const float x_val, const float y_val) : x(x_val) , y(y_val)
{

}

Point::Point(const Point &obj) : x(obj.x), y(obj.y)
{

}

Point& Point::operator=(const Point& obj)
{
	(void)obj;
	return *this;
}

float Point::getX(void) const
{
	return (x.toFloat());
}

float Point::getY(void) const
{
	return (y.toFloat());
}

Point::~Point()
{

}
