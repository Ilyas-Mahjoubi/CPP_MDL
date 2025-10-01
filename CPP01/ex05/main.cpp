/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:26:45 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/26 16:49:23 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// int main()
// {
// 	Harl harl;
// 	std::string input;
// 	std::cout << "========testing Harl complains========" << std::endl;

// 	std::cout << "level: ";
// 	std::getline(std::cin, input);
// 	harl.complain(input);
// 	return (0);
// }

#include <iostream>
#include <string>

int main()
{
	Harl harl;
	std::string input;

	std::cout << "======== testing Harl complains ========" << std::endl;

	while (true)
	{
		std::cout << "level (or type EXIT to quit): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "EXIT") {
			std::cout << "Exiting program...\n";
			break;
		}
		harl.complain(input);
	}
	return 0;
}
