/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:35:43 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/01 19:55:27 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), Hit_points(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
: Hit_points(obj.Hit_points) , Energy_points(obj.Energy_points), Attack_damage(obj.Attack_damage)
{}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->Attack_damage = obj.Attack_damage;
		this->Energy_points = obj.Energy_points;
		this->Hit_points = obj.Hit_points;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (Energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (Hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	Energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	Hit_points -=amount;
	if (Hit_points < 0)
		Hit_points = 0;
	std::cout << "ClapTrap " << name << " takes" << amount << " points of damage remaining HP: " << Hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to repair" << std::endl;
		return ;
	}
	if (Hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot repair" << std::endl;
		return ;
	}
	Energy_points--;
	Hit_points += amount;
	std::cout << "ClapTrap " << name << "He repair himself with " << amount << " point current Hp: " << Hit_points << std::endl;

}


ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
