/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:14:38 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/08 17:30:26 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "default constructor Animal called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal " << type << " is born!" << std::endl;
}
Animal::Animal(const Animal &obj)
: type(obj.type)
{}
Animal& Animal::operator=(const Animal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound..." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}
