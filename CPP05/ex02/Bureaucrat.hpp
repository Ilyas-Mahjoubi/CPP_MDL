/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:03:12 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/03 19:09:14 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"


class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade(int n);
		void decrementGrade(int n);

		void signAForm(AForm& AForm);

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
