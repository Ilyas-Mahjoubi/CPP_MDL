/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:55:08 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 16:55:10 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Constructor A zombie" << ZombieGetter() << " has spawned !\n";
}

Zombie::~Zombie()
{
	std::cout << "destructor : " << ZombieGetter() << " has been killed !\n";
}

void	Zombie::zombieSetter(std::string name)
{
	this->_name = name;
}

std::string Zombie::ZombieGetter(void)
{
	return (_name);
}

void Zombie::announce()
{
	std::cout << ZombieGetter() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
