/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:44:16 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 18:51:55 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Roboto myRequest", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Roboto myRequest", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
:target(obj.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecution(executor);

	srand(time(NULL));
	std::cout << "* Bzzzzzt! Drrrrrr! waaaaaaaa! *" << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	}
	else
		std::cout << "Robotomy failed on " << this->target << "." << std::endl;
}
