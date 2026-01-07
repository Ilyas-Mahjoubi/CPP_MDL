/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:06 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/07 15:01:16 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _datebase;
		void loadDatabase(const std::string& filename);
		void processLine(const std::string& line) const;
		static void trimWhitespace(std::string &str);
		bool checkDate(const std::string& date) const;
		float getExchangeRate(const std::string& date) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange& operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		void processInputFile(const std::string& filename);
};


#endif
