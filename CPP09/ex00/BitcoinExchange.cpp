/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:42:52 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/05 20:29:06 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	_datebase = obj._datebase;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		this->_datebase = obj._datebase;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}


void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");
	std::string line;
	std::getline(file, line); //this one only for me to skip the first line gg
	while (!std::getline(file, line))
	{
		size_t findcomma = line.find(",");

		if (findcomma != std::string::npos)
		{
			std::string date = line.substr(0, findcomma);
			std::string ratestr = line.substr(findcomma + 1);

			float rate = std::atof(ratestr.c_str());
			_datebase[date] = rate;
		}
	}
	file.close();
}

void BitcoinExchange::trimWhitespace(std::string &str)
{
	const std::string whitespace = "\n\r\t";
	size_t start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)
	{
		str = "";
		return ;
	}
	size_t end  = str.find_last_not_of(whitespace);
	str = str.substr(start, end - start + 1);
}

void BitcoinExchange::processLine(const std::string& line) const
{
	if(line.empty() || line == "data | value")
		return ;
	size_t findpospipe = line.find("|");
	// const std::string whitespace = "\n\r\t";
	// size_t found_date = line.find_first_not_of(whitespace);
	// size_t found_date_back = line.find_last_not_of(whitespace, findpos);
	
	if (findpospipe == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, findpospipe);
	std::string value_str = line. substr(findpospipe + 1);

	trimWhitespace(date);
	trimWhitespace(value_str);
}
