/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:24:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/15 18:40:15 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	_list = obj._list;
	_vec = obj._vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_list = obj. _list;
		this->_vec = obj._vec;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool	PmergeMe::check_input_and_fill(std::string arg)
{
		for(size_t j = 0; j < arg.size(); j++)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		long num;
		num = atol(av[i]);
		if (num < 0 || num > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec.push_back(num);
}
