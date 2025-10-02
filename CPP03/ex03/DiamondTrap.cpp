/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:40:36 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/02 21:43:45 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {std::cout << "DiamondTrap default constructor called" << std::endl;};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 30;
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj),  FragTrap(obj), ScavTrap(obj)
{
	this->name = obj.name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		this->name = obj.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
void DiamondTrap::whoAmI()
{
	std::cout<< "My DiamondTrap is " << this->name << " My ClapName is "<< ClapTrap::name<<std::endl;
}

// void DiamondTrap::attack(const std::string &target)
// {
// 	if (Energy_points <= 0)
// 	{
// 		std::cout << "DiamondTrap " << name << " has no energy to attack!" << std::endl;
// 		return ;
// 	}
// 	if (Hit_points <= 0)
// 	{
// 		std::cout << "DiamondTrap " << name << " is dead and cannot attack!" << std::endl;
// 		return ;
// 	}
// 	Energy_points--;
// 	std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
// }
