/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:24:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/19 18:56:36 by ilmahjou         ###   ########.fr       */
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

std::vector<int> PmergeMe::generateJacobsthal(int n)
	{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

	// Nzido hta nchofo size fin wsal;
	while (jacobsthal.back() < n)
	{
		int last = jacobsthal.back();
		int prev = jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(last + 2 * prev);
	}
	return jacobsthal;
}

std::vector<int> PmergeMe::fordJohnsonSortVec(std::vector<int> vec)
{
	std::vector<std::pair<int , int> > _vecPairs;
	std::vector<int> _winners;
	std::vector<int> pendingElements;
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
			_vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
		else
		{
			_winners.push_back(vec[i + 1]);
			_vecPairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		}
	}
	std::cout << ">>> Hbout: Size = " << vec.size() << " | Winners: ";
	for (size_t i = 0; i < _winners.size(); i++) std::cout << _winners[i] << " ";
		std::cout << std::endl;
	_winners = fordJohnsonSortVec(_winners);
	std::cout << "<<< Rjou3: Winners sorted: ";
	for (size_t i = 0; i < _winners.size(); i++)
		std::cout << _winners[i] << " ";
	std::cout << std::endl;
	std::vector<int> mainChain = _winners;
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = 0; j < _vecPairs.size(); j++)
		{
			if (mainChain[i] == _vecPairs[j].first)
			{
				pendingElements.push_back(_vecPairs[j].second);
				break;
			}
		}
	}
	if (!pendingElements.empty())
		mainChain.insert(mainChain.begin(), pendingElements[0]);
	std::vector<int> jacob = generateJacobsthal(pendingElements.size());
	// 3. Loop using Jacobsthal Indices
	// 'lastIndex' houwa fin wselna akher merra (bdina b 1 hit 0 dkhlnah)
	size_t lastIndex = 1;
	for (size_t k = 0; k < jacob.size(); k++)
	{
		// Jacobsthal number (Next limit)
		size_t currentJacob = jacob[k]; // e.g., 3, then 5, then 11...
		// Ma-khassnach nfoutou l'size dyal pending elements
		size_t limit = currentJacob;
		if (limit >= pendingElements.size())
			limit = pendingElements.size() - 1;
		// Hna fin kayn "L'Hila": Loop Backwards (Men limit htal lastIndex)
		// Mital: Men 3 htal 1 (ghay-dkhel 3, men b3d 2)
		while (limit >= lastIndex)
		{
			int valToInsert = pendingElements[limit];
			int buddyValue = -1;
			for (size_t p = 0; p < _vecPairs.size(); p++)
			{
					if (_vecPairs[p].second == valToInsert)
					{
						buddyValue = _vecPairs[p].first; // Found the winner!
						break;
					}
			}
			std::vector<int>::iterator buddyIt = std::find(mainChain.begin(), mainChain.end(), buddyValue);
			// 4. Binary Search (std::lower_bound)
			// Kima f tswira: Kan9lbou f mainChain 3la fin n7ettou valToInsert
			// end() hna hiya mainChain.end() hitash mainChain dima sorted
			std::vector<int>::iterator it;
			it = std::lower_bound(mainChain.begin(), buddyIt, valToInsert);
			// Insert
			mainChain.insert(it, valToInsert);
			//N9ess limit bash nrj3ou b'lor
			if (limit == 0) break; // Safety check
			limit--;
		}
		// Update lastIndex bash l'merra jaya nbdaou men fin salina
		// Matalan: Salina Group 3, db Group 5 ghadi ibda men 4
		lastIndex = currentJacob + 1;
	}

	// 5. Handle Odd Number (Struggler)
	// Ila kan 3ndk element chayt (only_1) khassou ydkhel f l'lkher
	if (_odd == -1) // awla kif ma smiti variable dyalk
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), only_1);
		mainChain.insert(it, only_1);
	}
	return mainChain;
}
