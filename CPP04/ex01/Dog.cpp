/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:09:18 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:15:41 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default constructor Dog <'*'> called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Animal " << type << " is born!" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &obj)
: Animal(obj.type)
{
	this->brain = new Brain(*obj.brain);
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return *this;
}

void Dog::setIdea(int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return this->brain->getIdea(index);
}

void Dog::makeSound() const
{
	std::cout << "Dogs don’t bark howwww howwww <'*'>" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog called howww howw <'*'>" << std::endl;
	delete this->brain;
}
