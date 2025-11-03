/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:02:54 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 19:09:24 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Toto"), grade(150)
{
	std::cout << "default constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
: name(obj.name) , grade(obj.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
		this->grade = obj.grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade(int n)
{
	if (grade - n < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade(int n)
{
	if (grade + n > 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void Bureaucrat::signAForm(AForm& AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->name << " signed " << AForm.getName() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr <<this->name << " couldn’t sign "  << AForm.getName() << " because "<< e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
