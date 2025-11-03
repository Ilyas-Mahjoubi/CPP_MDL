/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:44:10 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 18:59:37 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Roboto myRequest", 25, 5), target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Roboto myRequest", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
:target(obj.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
