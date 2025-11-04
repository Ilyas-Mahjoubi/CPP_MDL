/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:03:02 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/04 17:32:12 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "=================== test I: ShrubberyCreationForm========" << std::endl;
	try
	{
		Bureaucrat bob("bob", 100);
		ShrubberyCreationForm shrub("home");

		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;

		bob.signAForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n===================== test II: ShrubberyCreationForm - Not Signed ==========================" << std::endl;
	try
	{
		Bureaucrat bob2("bob2", 150);
		ShrubberyCreationForm shrub2("kitchen");

		bob2.executeForm(shrub2);
	}
	catch(const std::exception& e)
	{
		std::cerr<< "Error: " << e.what() << std::endl;
	}
	std::cout << "\n=================== test III: ShrubberyCreationForm - Grade low ===============================" << std::endl;
	try {
		Bureaucrat bob3("bob3", 150);
		ShrubberyCreationForm shrub3("bathroom");

		bob3.signAForm(shrub3);
		bob3.executeForm(shrub3);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "\n======================= test IV: RobotomyRequestForm - Success===================" << std::endl;
	try
	{
		Bureaucrat thilina("thili", 1);
		RobotomyRequestForm Robot ("xhul");

		std::cout << thilina << std::endl;
		std::cout << Robot << std::endl;

		thilina	.signAForm(Robot);
		thilina.executeForm(Robot);

	}
	catch(const std::exception& e)
	{
		std::cerr<< "Error: " << e.what() << '\n';
	}
	std::cout << "\n=================== test V: PresidentialPardonForm - Success =========================" << std::endl;
	try
	{
		Bureaucrat president("president", 5);
		PresidentialPardonForm pardon("pardon");

		std::cout << president << std::endl;
		std::cout << pardon << std::endl;

		president.signAForm(pardon);
		president.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}

	std::cout << "\n================================== test VI: Intern - Success ==================" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat boss("boss", 1);
		AForm* forms[3];
		
		forms[0] = intern.makeForm("shrubbery creation", "garden");
		forms[1] = intern.makeForm("robotomy request", "Marvin");
		forms[2] = intern.makeForm("presidential pardon", "Arthur Dent");
		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				std::cout << "\n" << *forms[i] << std::endl;
				boss.signAForm(*forms[i]);
				boss.executeForm(*forms[i]);
				delete forms[i];
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}
