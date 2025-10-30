/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:21:39 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 14:38:39 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "default constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
: type(obj.type)
{}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some generic WrongAnimal sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}
