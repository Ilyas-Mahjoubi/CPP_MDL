/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:43:01 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/02 19:50:08 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	Attack_damage = 20;
	Hit_points = 100;
	Energy_points = 50;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	ClapTrap::operator=(obj);
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
		if (Energy_points <= 0)
	{
		std::cout << "Scavtrap " << name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (Hit_points <= 0)
	{
		std::cout << "Scavtrap " << name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	Energy_points--;
	std::cout << "Scavtrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
}
