/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:06 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/05 20:27:35 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _datebase;
		void loadDatabase(const std::string& filename);
		void processLine(const std::string& line) const;
		static void trimWhitespace(std::string &str);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange& operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
};


#endif
