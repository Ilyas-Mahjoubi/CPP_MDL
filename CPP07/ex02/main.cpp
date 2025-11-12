/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:31:26 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/12 18:16:43 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	std::cout << "================Test 1: Empty array==============" << std::endl;
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;
	
	std::cout << "================Test 2: Array with size==============" << std::endl;
	Array<int> numbers(5);
	std::cout << "Numbers size: " << numbers.size() << std::endl;
	
	std::cout << "================Test 3: Fill and print==============" << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	
	std::cout << "================Test 4: Copy==============" << std::endl;
	Array<int> copy = numbers;
	copy[0] = 999;
	std::cout << "Original[0]: " << numbers[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << std::endl;

	std::cout << "================Test 5: Out of bounds==============" << std::endl;
	try {
		numbers[100] = 42;
	} catch (std::exception & e) {
		std::cout << "Exception caught!" << std::endl;
	}
	return 0;
}
