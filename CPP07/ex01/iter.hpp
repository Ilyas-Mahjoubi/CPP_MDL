/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:38:04 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/11 18:00:56 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printElent(T const & x)
{
	std::cout << x << std::endl;
}

template <typename T, typename F>
void iter(T* array, size_t len, F func)
{
	for(size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

#endif
