/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:24:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/24 19:43:30 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	_dq = obj._dq;
	_vec = obj._vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_dq = obj. _dq;
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

std::deque<int> PmergeMe::getdq()
{
	return this->_dq;
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
	this->_dq.push_back(n);
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

// int PmergeMe::creatpairvec(std::vector<int> &input, std::vector<int> &_winners, std::vector<std::pair<int, int> > &Pairs)
// {
// 	int _odd = -1;

// 	if (input.size() % 2 != 0)
// 	{
// 		_odd = input.back();
// 		input.pop_back();
// 	}
// 	for(size_t i = 0; i < input.size(); i +=2)
// 	{
// 		if (input[i] >= input[i + 1])
// 		{
// 			_winners.push_back(input[i]);
// 			Pairs.push_back(std::make_pair(input[i], input[i + 1]));
// 		}
// 		else
// 		{
// 			_winners.push_back(input[i + 1]);
// 			Pairs.push_back(std::make_pair(input[i + 1], input[i]));
// 		}
// 	}
// 	return _odd;
// }

// std::vector<int> PmergeMe::Buildpending(std::vector<int> &mainc, std::vector<std::pair<int, int> > &Pairs)
// {
// 	std::vector<int> pending;
// 	for (size_t i = 0; i < mainc.size(); i++)
// 	{
// 		for (size_t j = 0; j < Pairs.size(); j++)
// 		{
// 			if (mainc[i] == Pairs[j].first)
// 			{
// 				pending.push_back(Pairs[j].second);
// 				break ;
// 			}
// 		}
// 	}
// 	return pending;
// }

// void PmergeMe::insertPending(std::vector<int> &mainc, std::vector<int> &pending, std::vector<std::pair<int, int> > &Pairs)
// {
// 	std::vector<int> jacob = generateJacobsthal(pending.size());
// 	// 3. Loop using Jacobsthal Indices
// 	// 'lastIndex' houwa fin wselna akher merra (bdina b 1 hit 0 dkhlnah)
// 	size_t lastIndex = 1;
// 	for (size_t k = 0; k < jacob.size(); k++)
// 	{
// 		// Jacobsthal number (Next limit)
// 		size_t currentJacob = jacob[k]; // e.g., 3, then 5, then 11...
// 		// Ma-khassnach nfoutou l'size dyal pending elements
// 		size_t limit = currentJacob;
// 		if (limit >= pending.size())
// 			limit = pending.size() - 1;
// 		// Hna fin kayn "L'Hila": Loop Backwards (Men limit htal lastIndex)
// 		// Mital: Men 3 htal 1 (ghay-dkhel 3, men b3d 2)
// 		while (limit >= lastIndex)
// 		{
// 			int valToInsert = pending[limit];
// 			int buddyValue = -1;
// 			for (size_t p = 0; p < Pairs.size(); p++)
// 			{
// 					if (Pairs[p].second == valToInsert)
// 					{
// 						buddyValue = Pairs[p].first; // Found the winner!
// 						break;
// 					}
// 			}
// 			std::vector<int>::iterator buddyIt = std::find(mainc.begin(), mainc.end(), buddyValue);
// 			// 4. Binary Search (std::lower_bound)
// 			// Kima f tswira: Kan9lbou f mainChain 3la fin n7ettou valToInsert
// 			// end() hna hiya mainChain.end() hitash mainChain dima sorted
// 			std::vector<int>::iterator it;
// 			it = std::lower_bound(mainc.begin(), buddyIt, valToInsert);
// 			// Insert
// 			mainc.insert(it, valToInsert);
// 			//N9ess limit bash nrj3ou b'lor
// 			if (limit == 0) break; // Safety check
// 			limit--;
// 		}
// 		// Update lastIndex bash l'merra jaya nbdaou men fin salina
// 		// Matalan: Salina Group 3, db Group 5 ghadi ibda men 4
// 		lastIndex = currentJacob + 1;
// 	}
// }

std::vector<int> PmergeMe::fordJohnsonSortVec(std::vector<int> vec)
{
	std::vector<std::pair<int , int> > _vecPairs;
	std::vector<int> _winners;
	std::vector<int> pendingElements;

	if (vec.size() <= 1)
	{
		return vec;
	}
	int _odd = creatpair(vec, _winners, _vecPairs);

	_winners = fordJohnsonSortVec(_winners);
	std::vector<int> mainChain = _winners;
	pendingElements = Buildpending(mainChain, _vecPairs);
	if (!pendingElements.empty())
		mainChain.insert(mainChain.begin(), pendingElements[0]);
	insertPending(mainChain, pendingElements, _vecPairs);
	if (_odd != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), _odd);
		mainChain.insert(it, _odd);
	}
	return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonSortDq(std::deque<int> Dq)
{
	std::deque<std::pair<int , int> > _DqPairs;
	std::deque<int> _winners;
	std::deque<int> pendingElements;

	if (Dq.size() <= 1)
	{
		return Dq;
	}
	int _odd = creatpair(Dq, _winners, _DqPairs);

	_winners = fordJohnsonSortDq(_winners);
	std::deque<int> mainChain = _winners;
	pendingElements = Buildpending(mainChain, _DqPairs);
	if (!pendingElements.empty())
		mainChain.insert(mainChain.begin(), pendingElements[0]);
	insertPending(mainChain, pendingElements, _DqPairs);
	if (_odd != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), _odd);
		mainChain.insert(it, _odd);
	}
	return mainChain;
}

