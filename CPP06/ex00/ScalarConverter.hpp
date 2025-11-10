/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:06:53 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/10 17:43:37 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
		
		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);
		static bool isSpecialFloat(const std::string& str);
		static bool isSpecialDouble(const std::string& str);

		static void printChar(double value, bool impossible);
		static void printInt(double value, bool impossible);
		static void printFloat(double value);
		static void printDouble(double value);
		public :
			static void convert(const std::string& literal);
	};
	
#endif
