/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:48:23 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 20:17:17 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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
	// Array of known form names
	std::string formNames[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	// Find the index of the formName
	int i = 0;
	while (i < 3 && formNames[i] != formName)
	{
		i++;
	}

	AForm* newForm = NULL;

	// Use a switch to create the correct form
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
			// If no match is found (i == 3), print an error
			std::cout << "Error: Intern cannot create form '" << formName 
					  << "'. Form name not recognized." << std::endl; [cite: 237]
			return NULL;
	}

	// On success, print creation message
	std::cout << "Intern creates " << newForm->getName() << std::endl; [cite: 236]
	return newForm;
}
