/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:54:44 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 15:35:01 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

static std::string formatField(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact()
{
		std::string f, l, n, p, d;

		std::cout << "First Name: "; std::getline(std::cin, f);
		std::cout << "Last Name: "; std::getline(std::cin, l);
		std::cout << "Nickname: "; std::getline(std::cin, n);
		std::cout << "Phone Number: "; std::getline(std::cin, p);
		std::cout << "Darkest Secret: "; std::getline(std::cin, d);
		contacts[nextIndex].setContact(f, l, n, p, d);
		if (count < 8)
			count++;
		nextIndex = (nextIndex + 1) % 8;
}

void PhoneBook::searchContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << formatField(contacts[i].getLastName()) << "|"
					<< std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter index to view details: ";
	int idx;
	if (!(std::cin >> idx))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input!" << std::endl;
		return;
	}
	std::cin.ignore();

	if (idx >= 1 && idx <= count)
		contacts[idx - 1].displayFull();
	else
		std::cout << "Invalid index!" << std::endl;
}
