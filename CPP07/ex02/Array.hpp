/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:24:06 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/12 18:03:38 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>

class Array
{
	private :
		T* _array;
		unsigned int _size;
	public :
		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		~Array();
		T& operator[](unsigned int index);
		unsigned int size() const;
};

#include "Array.tpp"

#endif
