/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:27:41 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 14:38:12 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "default constructor WrongCat meww <._.> called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << type << " : waahwwwwwwww ! (WrongCat) ... " << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called waahwwwwwwww <._.>" << std::endl;
}
