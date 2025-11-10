/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:06:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/10 18:04:39 by ilmahjou         ###   ########.fr       */
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


/* bool ScalarConverter::isChar(const std::string& str)
{
	if ((str.length() == 1 && std::isalpha(str[0])) || std::isprint(str[0]))
	{
		return (true);
	}
	return (false);
} */

bool ScalarConverter::isChar(const std::string& str)
{
	if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
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
	{
		return false;
	}
	if (str[str.length() - 1] != 'f')
	{
		return false;
	}
	// for (int i = 0; i < str.length(); i++)
	// {
	// 	if (((str[i] >= 'a' && str[i] <= 'e') && (str[i] >= 'g' && str[i] <= 'z')) || ((str[i] >= 'A' && str[i] <= 'E') && (str[i] >= 'G' && str[i] <= 'Z')))
	// 		return false;
	// }
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
	{
		return true;
	}
	if (str.find('.') == std::string::npos)
	{
		return false;
	}
	return true;
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
	if (str.find('.') == std::string::npos)
	{
		return false;
	}
	return true;
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
		std::cout << "Int: impossible" << std::endl;
	}
	else if( value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "Int: impossible" << std::endl;
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

// void ScalarConverter::convert(const std::string& literal)
// {
// 	double value = 0.0;
// 	bool impossible = false;

// 	if (isChar(literal))
// 	{
// 		if (literal.length() == 1) {
// 			value = static_cast<double>(literal[0]);
// 		}
// 		else if (literal.length() == 3) {
// 			value = static_cast<double>(literal[1]);
// 		}
// 	}
// 	else if (isInt(literal))
// 	{

// 	}
// 	printChar(value, impossible);
// }

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
			if (literal[0] == '-') value = -value;
		}
	}
	else if (isFloat(literal))
	{
		std::string temp = literal.substr(0, literal.length() - 1);
		value = std::strtod(temp.c_str(), NULL);
	}
	else if (isInt(literal))
	{
		value = std::atoi(literal.c_str());
	}
	else
	{
		value = std::strtod(literal.c_str(), NULL);
	}
	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value);
	printDouble(value);
}
