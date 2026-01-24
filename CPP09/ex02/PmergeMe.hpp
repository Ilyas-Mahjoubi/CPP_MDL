/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:22:42 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/24 19:55:31 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sys/time.h>
#include <cstdlib>
#include <deque>
#include <list>
#include <climits>
#include <algorithm>

class PmergeMe
{
	private :
		std::vector<int> _vec;
		std::deque<int> _dq;
		std::vector<int> generateJacobsthal(int n);

		template <typename Container, typename PairContainer>
		int creatpair(Container &input, Container &_winners, PairContainer &Pairs);

		template <typename Container, typename PairContainer>
		Container Buildpending(Container &mainc, PairContainer &Pairs);

		template <typename Container, typename PairContainer>
		void insertPending(Container &mainc, Container &pending, PairContainer &Pairs);
	public :
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		bool	check_input(std::string);
		std::vector<int> getVec();
		std::deque<int> getdq();
		std::vector<int> fordJohnsonSortVec(std::vector<int> vec);
		std::deque<int> fordJohnsonSortDq(std::deque<int> vec);
		template <typename Container>
		void print_vec_Dq(Container);
};

template <typename Container, typename PairContainer>
int PmergeMe::creatpair(Container &input, Container &_winners, PairContainer &Pairs)
{
	int _odd = -1;

	if (input.size() % 2 != 0)
	{
		_odd = input.back();
		input.pop_back();
	}
	for(size_t i = 0; i < input.size(); i +=2)
	{
		if (input[i] >= input[i + 1])
		{
			_winners.push_back(input[i]);
			Pairs.push_back(std::make_pair(input[i], input[i + 1]));
		}
		else
		{
			_winners.push_back(input[i + 1]);
			Pairs.push_back(std::make_pair(input[i + 1], input[i]));
		}
	}
	return _odd;
}

template <typename Container, typename PairContainer>
Container PmergeMe::Buildpending(Container &mainc, PairContainer &Pairs)
{
	Container pending;
	for (size_t i = 0; i < mainc.size(); i++)
	{
		for (size_t j = 0; j < Pairs.size(); j++)
		{
			if (mainc[i] == Pairs[j].first)
			{
				pending.push_back(Pairs[j].second);
				break ;
			}
		}
	}
	return pending;
}

template <typename Container, typename PairContainer>
void	PmergeMe::insertPending(Container &mainc, Container &pending, PairContainer &Pairs)
{
	std::vector<int> jacob = generateJacobsthal(pending.size());
	// 3. Loop using Jacobsthal Indices
	// 'lastIndex' houwa fin wselna akher merra (bdina b 1 hit 0 dkhlnah)
	size_t lastIndex = 1;
	for (size_t k = 0; k < jacob.size(); k++)
	{
		// Jacobsthal number (Next limit)
		size_t currentJacob = jacob[k]; // e.g., 3, then 5, then 11...
		// Ma-khassnach nfoutou l'size dyal pending elements
		size_t limit = currentJacob;
		if (limit >= pending.size())
			limit = pending.size() - 1;
		// Hna fin kayn "L'Hila": Loop Backwards (Men limit htal lastIndex)
		// Mital: Men 3 htal 1 (ghay-dkhel 3, men b3d 2)
		while (limit >= lastIndex)
		{
			int valToInsert = pending[limit];
			int buddyValue = -1;
			for (size_t p = 0; p < Pairs.size(); p++)
			{
					if (Pairs[p].second == valToInsert)
					{
						buddyValue = Pairs[p].first; // Found the winner!
						break;
					}
			}
			typename Container::iterator buddyIt = std::find(mainc.begin(), mainc.end(), buddyValue);
			// 4. Binary Search (std::lower_bound)
			// Kima f tswira: Kan9lbou f mainChain 3la fin n7ettou valToInsert
			// end() hna hiya mainChain.end() hitash mainChain dima sorted
			typename Container::iterator it;
			it = std::lower_bound(mainc.begin(), buddyIt, valToInsert);
			// Insert
			mainc.insert(it, valToInsert);
			//N9ess limit bash nrj3ou b'lor
			if (limit == 0) break; // Safety check
			limit--;
		}
		// Update lastIndex bash l'merra jaya nbdaou men fin salina
		// Matalan: Salina Group 3, db Group 5 ghadi ibda men 4
		lastIndex = currentJacob + 1;
	}
}

template <typename Container>
void PmergeMe::print_vec_Dq(Container cnt)
{
	for(size_t i = 0; i < cnt.size(); i++)
	{
		if (i == 10)
		{
			std::cout<< "[..]";
			break;
		}
		std::cout << cnt[i] << " ";
	}
}

#endif
