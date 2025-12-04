/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:26:35 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/12/04 20:00:19 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);


	std::cout<< "========================test with vector================" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found for vec: " << *it << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Not found!" << '\n';
	}

	std::cout << "======================= test with list ================" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "Found for list: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Not found!" << '\n';
	}

	std::cout << "============== test for the errors ==============" << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, -42);
		std::cout << "Found: "<< *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "-42 not found!" << '\n';
	}
}
