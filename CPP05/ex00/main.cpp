/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:03:02 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/30 19:36:34 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
		bob.incrementGrade(1);
		std::cout << bob << std::endl;
		Bureaucrat alice("Alice", 0);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Bureaucrat charlie("Charlie", 151);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
