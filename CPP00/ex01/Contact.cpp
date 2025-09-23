/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:53:10 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 15:03:44 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

/*FOR MAKE IT SHORT :)*/
void Contact::setContact(std::string f, std::string l, std::string n, std::string p, std::string d)
{
	firstName = f;
	lastName = l;
	nickname = n;
	phoneNumber = p;
	darkestSecret = d;
}
/*FOR THE FIRST NAME BC IS PRV*/
std::string Contact::getFirstName() const
{
	return firstName;
}
/*FOR THE LAST NAME BC IS PRV*/
std::string Contact::getLastName() const
{
	return lastName;
}
/*FOR THE NICK NAME BC IS PRV*/
std::string Contact::getNickname() const
{
	return nickname;
}
/*FOR THE DISPLAY*/
void Contact::displayFull() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
