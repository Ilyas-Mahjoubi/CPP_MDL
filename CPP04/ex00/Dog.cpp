/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:09:18 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/08 17:30:38 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default constructor Dog <'*'> called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Animal " << type << " is born!" << std::endl;
}

Dog::Dog(const Dog &obj)
: Animal(obj.type)
{}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dogs don’t bark howwww howwww <'*'>" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called howww howw <'*'>" << std::endl;
}
