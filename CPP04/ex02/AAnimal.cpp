/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:14:38 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 14:55:05 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "default constructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal " << type << " is born!" << std::endl;
}
AAnimal::AAnimal(const AAnimal &obj)
: type(obj.type)
{}
AAnimal& AAnimal::operator=(const AAnimal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

std::string AAnimal::getType() const
{
	return type;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor AAnimal called" << std::endl;
}
