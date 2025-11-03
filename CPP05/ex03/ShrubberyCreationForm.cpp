/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:42:07 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 19:45:31 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery Creation", 145, 137), target("Default")
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
: target(obj.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("could not creat a file");
	file << "       ###\n";
	file << "      #o###\n";
	file << "    #o###o###\n";
	file << "   #o#\\#|#/###\n";
	file << "    ###\\|/###\n";
	file << "     # }|{ #\n";
	file << "       }|{\n";
	file.close();
}
