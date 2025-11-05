/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:06:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/05 20:10:05 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter(){}


bool ScalarConverter::isChar(const std::string& str)
{
	if (str.length() == 1 && std::isalpha(str[0]) || std::isprint(str[0]))
	{
		return (true);
	}
	return (false);
}

bool ScalarConverter::isInt(const std::string& str)
{
	
}
