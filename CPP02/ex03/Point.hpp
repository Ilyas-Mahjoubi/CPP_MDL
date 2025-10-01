/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:16:57 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/01 16:37:03 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float x_val, const float y_val);
		Point(const Point &obj);
		Point& operator=(const Point& obj);

		float getX(void) const;
		float getY(void) const;
		~Point();

};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif
