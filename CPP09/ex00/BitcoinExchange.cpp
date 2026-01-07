/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:42:52 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/07 15:51:34 by ilmahjou         ###   ########.fr       */
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
	while (std::getline(file, line))
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
	const std::string whitespace = " \n\r\t";
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

	if (findpospipe == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, findpospipe);
	std::string value_str = line. substr(findpospipe + 1);

	trimWhitespace(date);
	trimWhitespace(value_str);

	if (!checkDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return ;
	}

	char *endptr;
	float value = std::strtof(value_str.c_str(), &endptr);

	if (*endptr != '\0')
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return ;
	}

	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}

	try
	{
		float rate = getExchangeRate(date);
		float res = value * rate;
		std::cout << date << " => " << value << " = " << res << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

bool BitcoinExchange::checkDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	//int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month == 2 && day > 29)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _datebase.lower_bound(date);

	if (it != _datebase.end() && it->first == date)
		return it->second;
	if (it == _datebase.begin())
		throw std::runtime_error("Error: no earlier date in database.");
	--it;
	return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "the file not started with *date | value*" << std::endl;
		file.close();
		return ;
	}
	while (std::getline(file, line))
	{
		processLine(line);
	}
	file.close();
}
