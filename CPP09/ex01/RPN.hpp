/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:32:50 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/08 12:32:57 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN &obj);
		RPN& operator=(const RPN &obj);
		~RPN();

		void calculate(std::string input);
};

#endif
