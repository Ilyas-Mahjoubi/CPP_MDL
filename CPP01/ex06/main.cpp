/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:22:25 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/26 17:57:22 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	harl.complain(av[1]);
	return (0);
}

// #include <iostream>
// #include <string>

// int main()
// {
// 	Harl harl;
// 	std::string input;

// 	std::cout << "======== testing Harl complains ========" << std::endl;

// 	while (true)
// 	{
// 		std::cout << "level (or type EXIT to quit): ";
// 		std::getline(std::cin, input);
// 		if (std::cin.eof())
// 			return (0);
// 		if (input == "EXIT") {
// 			std::cout << "Exiting program...\n";
// 			break;
// 		}
// 		harl.complain(input);
// 	}
// 	return 0;
// }
