/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:32:41 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/08 19:25:59 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &obj)
{
	_stack = obj._stack;
}

RPN& RPN::operator=(const RPN &obj)
{
	if (this != &obj)
	{
		this->_stack = obj._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::calculate(std::string input)
{
	std::stringstream ss(input);
	std::stack<int> stack;
	std::string token;
	int res = 0;

	while (std::getline(ss, token, ' '))
	{
		if (token.empty())
			continue;
		if (token == "-" || token == "+" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			if (token == "-")
				res = a - b;
			else if (token == "+")
				res = a + b;
			else if (token == "*")
				res = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("u cant / by 0");
				res = a / b;
			}
			_stack.push(res);
		}
		else if (token.size() == 1 && isdigit(token[0]))
		{
			_stack.push(atoi(token.c_str()));
		}
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::runtime_error("Error");
}
