/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:48:12 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/08 17:30:33 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "default constructor cat meww <._.> called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Animal " << type << " is born!" << std::endl;
}

Cat::Cat(const Cat &obj)
: Animal(obj.type)
{}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "cats don’t bark meeeewwwww <._.>" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat called meeeewwwww <._.>" << std::endl;
}
