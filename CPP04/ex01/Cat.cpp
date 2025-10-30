/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:48:12 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:16:38 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "default constructor cat meww <._.> called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Animal " << type << " is born!" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &obj)
: Animal(obj.type)
{
	this->brain = new Brain(*obj.brain);
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return *this;
}

void Cat::setIdea(int index, const std::string& idea)
{
	this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return this->brain->getIdea(index);
}

void Cat::makeSound() const
{
	std::cout << "cats don’t bark meeeewwwww <._.>" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called meeeewwwww <._.>" << std::endl;
	delete this->brain;
}
