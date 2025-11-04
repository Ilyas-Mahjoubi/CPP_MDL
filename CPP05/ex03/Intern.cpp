/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:48:23 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/04 17:12:48 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}
Intern::Intern(const Intern& obj)
{
	(void)obj;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Destructor Intern called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	int i = 0;
	while (i < 3 && formNames[i] != formName)
	{
		i++;
	}
	AForm* newForm = NULL;
	switch (i)
	{
		case 0:
			newForm = new RobotomyRequestForm(target);
			break;
		case 1:
			newForm = new PresidentialPardonForm(target);
			break;
		case 2:
			newForm = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "Error: Intern cannot create form '" << formName \
			  << "'. Form name not recognized." << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << newForm->getName() << std::endl;
	return newForm;
}
