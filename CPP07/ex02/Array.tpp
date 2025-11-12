/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:24:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/12 18:07:03 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n)
{
}
template<typename T>
Array<T>::Array(const Array& obj) : _array(NULL), _size(0)
{
	*this = obj;
}
template<typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this != &obj)
	{
		delete [] _array;
		_size = obj._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = obj._array[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if(index >= _size)
		throw std::exception();
	return _array[index];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
