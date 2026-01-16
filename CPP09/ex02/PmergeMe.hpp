/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:22:42 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/16 20:39:52 by ilmahjou         ###   ########.fr       */
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

class PmergeMe
{
	private :
		std::vector<int> _vec;
		std::list<int> _list;
		//std::vector<int> generateJacobsthal(int n);
	public :
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();


		bool	check_input(std::string);
		std::vector<int> getVec();
		std::vector<int> fordJohnsonSortVec(std::vector<int> vec);
};

#endif
