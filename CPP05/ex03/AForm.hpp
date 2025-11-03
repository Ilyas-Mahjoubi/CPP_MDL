/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:26:03 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/02 18:09:12 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	protected:
		void checkExecution(const Bureaucrat& executor) const;
	private:
		const	std::string _name;
		bool	_isSigned;
		const int	gradeToSign;
		const int gradeToExecute;
	public:
		AForm();
		AForm(std::string _name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		~AForm();

		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;


		void beSigned(const Bureaucrat& bureaucrat);

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
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);


#endif
