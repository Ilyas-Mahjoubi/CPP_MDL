/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:03:02 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 17:19:21 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Test I: Create forms and bureaucrats ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 55);
		Form taxForm("Tax Form", 44, 31);

		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test II: Bureaucrat can't sign (grade too low) ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 55);
		Form taxForm("Tax Form", 44, 31);

		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test III: Bureaucrat can sign ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 55);
		Form taxForm("Tax Form", 44, 31);

		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n=== Test IV: Invalid form grades ===" << std::endl;
	try {
		Form badForm("Bad Form", 0, 31);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	try {
		Form badForm2("Bad Form 2", 44, 200);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
