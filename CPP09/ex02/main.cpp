/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:22:31 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/17 19:40:15 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int main(int ac, char **av)
// {
// 	if (ac < 2)
// 	{
// 		std::cerr << "Error u need more args" << std::endl;
// 		std::cerr << "Use: ./PmergeMe [positive integer]" << std::endl;
// 		return 1;
// 	}
// 	std::vector<int> vec;
// 	for(int i = 1; i < ac; i++)
// 	{
// 		std::string arg = av[i];
// 		for(size_t j = 0; j < arg.size(); j++)
// 		{
// 			if (!isdigit(arg[j]))
// 			{
// 				std::cerr << "Error" << std::endl;
// 				return 1;
// 			}
// 		}
// 		long num;
// 		num = atol(av[i]);
// 		if (num < 0 || num > INT_MAX)
// 		{
// 			std::cerr << "Error" << std::endl;
// 			return 1;
// 		}
// 		vec.push_back(num);
// 	}
// 	std::cout << "Before: ";
// 	for(size_t i = 0; i < vec.size(); i++)
// 	{
// 		std::cout << vec[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << "After: ";
// 	PmergeMe pmer;
// 	struct timeval start, end;
// 	gettimeofday(&start, NULL);
// 	pmer.fordJohnsonSortVec(vec);
// 	gettimeofday(&end, NULL);
// 	double timeVec = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
// 	for(size_t i = 0; i < vec.size(); i++)
// 	{
// 		std::cout << vec[i] << " ";
// 	}
// 	std::cout<<std::endl;
// 	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us"<< std::endl;
// }


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
	for(size_t i = 0; i < _merg.getVec().size(); i++)
	{
		std::cout << _merg.getVec()[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> sorted = _merg.fordJohnsonSortVec(_merg.getVec());
	std::cout << "After: ";
	for(size_t i = 0; i < sorted.size(); i++)
	{
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
}
