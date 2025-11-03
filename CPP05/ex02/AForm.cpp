/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:26:00 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 17:39:39 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


AForm::AForm() : _name("Default AForm"), _isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Default constructor AForm called" << std::endl;
}

AForm::AForm(std::string _name, int gradeToSign, int gradeToExecute) : _name(_name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& obj)
: _name(obj._name), _isSigned(obj._isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{

}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor AForm called" << std::endl;
}
std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

bool AForm::isSigned() const
{
	return this->_isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm " << AForm.getName()
		<< ", signed: " << AForm.isSigned()
		<< ", grade required to sign: " << AForm.getGradeToSign()
		<< ", grade required to execute: " << AForm.getGradeToExecute();
	return out;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
	if (!this->_isSigned)
		throw std::runtime_error("Form is not signed");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
}
