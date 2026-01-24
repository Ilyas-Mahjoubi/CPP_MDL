/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:22:31 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/24 19:57:41 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error u need more args" << std::endl;
		std::cerr << "Use: ./PmergeMe [positive integer]" << std::endl;
		return 1;
	}
	PmergeMe _merg;
	std::vector<int> vec;
	for(int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		if (!_merg.check_input(str))
		{
			return 1;
		}
	}
	std::cout << "Before: ";
	_merg.print_vec_Dq(_merg.getVec());
	std::cout << std::endl;
	std::vector<int> vr = _merg.getVec();
	std::vector<int> sortedvc;
	struct timeval start, stop;
	gettimeofday(&start, NULL);
	sortedvc = _merg.fordJohnsonSortVec(vr);
	gettimeofday(&stop, NULL);
	std::cout << "After: ";
	_merg.print_vec_Dq(sortedvc);
	std::cout << std::endl;
	double _time_sort_vec = (stop.tv_sec - start.tv_sec) * 1000000.0 + (stop.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << vr.size()
				<< " elements with std::vector  : "
				<< std::fixed << std::setprecision(5) << _time_sort_vec << " us" << std::endl;
	std::deque<int> dq = _merg.getdq();
	std::deque<int> sorted_dq;
	struct timeval startd, stopd;
	gettimeofday(&startd, NULL);
	sorted_dq = _merg.fordJohnsonSortDq(dq);
	gettimeofday(&stopd, NULL);
	double _time_sort_deque = (stopd.tv_sec - startd.tv_sec) * 1000000.0 + (stopd.tv_usec - startd.tv_usec);
		std::cout << "Time to process a range of " << dq.size()
				<< " elements with std::deque  : "
				<< std::fixed << std::setprecision(5) << _time_sort_deque << " us" << std::endl;
}
