/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:06:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/27 17:31:39 by ilmahjou         ###   ########.fr       */
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
	//std::cout << "look here ==> " << str.length() << std::endl;
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& str)
{
	if (str.empty())
		return false;
	if (isChar(str))
		return false;
	if (str.find('.') != std::string::npos)
		return false;
	if (str.find('f') != std::string::npos)
		return false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if ( i >= str.length())
		return false;
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}

	return true;
}
//maybe i have to do same checks :(
bool ScalarConverter::isFloat(const std::string& str)
{
	if (str.empty())
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
		return true;
	std::string num = str.substr(0, str.length() - 1);
	if (num.empty())
		return false;
	size_t dotcount = 0;
	size_t i = 0;
	if (num[0] == '+' || num[0] == '-')
		i = 1;
	if (i >= num.length())
		return false;
	for (; i < num.length(); i++)
	{
		if (num[i] == '.')
			dotcount++;
		else if (!std::isdigit(num[i]))
			return false;
	}
	return dotcount == 1;
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str.empty())
	{
		return false;
	}
	if (isChar(str) || isInt(str) || isFloat(str))
	{
		return false;
	}
	if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
	{
		return true;
	}
	size_t dotcount = 0;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (i >= str.length())
		return false;
	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
			dotcount++;
		else if (!std::isdigit(str[i]))
			return false;
	}
	return dotcount == 1;
}
bool ScalarConverter::isSpecialFloat(const std::string& str)
{
	return (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf");
}
bool ScalarConverter::isSpecialDouble(const std::string& str)
{
	return (str == "-inf" || str == "+inf" || str == "inf" || str == "nan");
}

void ScalarConverter::printChar(double value, bool impossible)
{
	if (impossible || std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (value < 32 || value > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

void ScalarConverter::printInt(double value, bool impossible)
{
	if (impossible || std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
	}
	else if( value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printFloat(double value)
{
	float f = static_cast<float>(value);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	double value = 0.0;
	bool impossible = false;

	if (isChar(literal))
	{
		if (literal.length() == 1)
		{
			value = static_cast<double>(literal[0]);
		}
		else if (literal.length() == 3)
		{
			value = static_cast<double>(literal[1]);
		}
	}
	else if (isSpecialFloat(literal) || isSpecialDouble(literal))
	{
		if (literal == "nanf" || literal == "nan")
		{
			value = std::numeric_limits<double>::quiet_NaN();
		}
		else
		{
			value = std::numeric_limits<double>::infinity();
			if (literal[0] == '-')
			{
				value = -value;
			}
		}
	}
	else if (isFloat(literal))
	{
		std::string temp = literal.substr(0, literal.length() - 1);
		value = std::strtod(temp.c_str(), NULL);
	}
	else if (isInt(literal))
	{
		value = std::atol(literal.c_str());
	}
	else
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value);
	printDouble(value);
}
