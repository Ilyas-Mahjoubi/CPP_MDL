/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:24:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/16 21:32:52 by ilmahjou         ###   ########.fr       */
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

std::vector<int> PmergeMe::getVec()
{
	return this->_vec;
}

bool	PmergeMe::check_input(std::string str)
{
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
	}
	long num;
	num = atol(str.c_str());
	if (num < 0 || num > INT_MAX)
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	int n = num;
	this->_vec.push_back(n);
	return true;
}

std::vector<int> PmergeMe::fordJohnsonSortVec(std::vector<int> vec)
{
	std::vector<std::pair<int , int> > _vecPairs;
	std::vector<int> _winners;
	std::vector<int> _losers;
	int only_1;
	int _odd = 1;

	if (vec.size() <= 1)
	{
		return vec;
	}
	if (vec.size() % 2 != 0)
	{
		only_1 = vec.back();
		vec.pop_back();
		_odd = -1;
	}
	for(size_t i = 0; i < vec.size(); i +=2)
	{
		if (vec[i] >= vec[i + 1])
		{
			_winners.push_back(vec[i]);
			_losers.push_back(vec[i + 1]);
			_vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
		else
		{
			_losers.push_back(vec[i]);
			_winners.push_back(vec[i + 1]);
			_vecPairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		}
	}
	_winners = fordJohnsonSortVec(_winners);
	std::cout << "Stored Pairs (Winner -> Loser): " << std::endl;
	for (size_t i = 0; i < _vecPairs.size(); i++) {
		std::cout << "  [ " << _vecPairs[i].first << " , " << _vecPairs[i].second << " ]" << std::endl;
	}
	std::vector<int> mainChain = _winners;
	//return _winners;
	
}
