/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:26:00 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 16:50:27 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form() : _name("Default Form"), _isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Default constructor Form called" << std::endl;
}

Form::Form(std::string _name, int gradeToSign, int gradeToExecute) : _name(_name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& obj)
: _name(obj._name), _isSigned(obj._isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor Form called" << std::endl;
}
std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too Low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() 
		<< ", signed: " << form.isSigned()
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute();
	return out;
}
