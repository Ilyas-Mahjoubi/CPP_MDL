/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:35:49 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/02 22:13:08 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "====== Testing DiamondTrap Creation ======" << std::endl;
	DiamondTrap diamond("Diamond");
	std::cout << std::endl;

	std::cout << "====== Testing whoAmI() ======" << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	std::cout << "====== Testing Attack (should use ScavTrap's attack) ======" << std::endl;
	diamond.attack("target");
	std::cout << std::endl;

	std::cout << "====== Testing Inherited Functions ======" << std::endl;
	diamond.takeDamage(50);
	diamond.beRepaired(30);
	std::cout << std::endl;

	std::cout << "====== Testing Special Abilities from Parents ======" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();
	std::cout << std::endl;

	std::cout << "====== Testing with another DiamondTrap ======" << std::endl;
	DiamondTrap diamond2("Sparkle");
	diamond2.whoAmI();
	diamond2.attack("another_target");
	std::cout << std::endl;

	std::cout << "====== Testing Copy Constructor ======" << std::endl;
	DiamondTrap diamond3(diamond);
	diamond3.whoAmI();
	std::cout << std::endl;

	std::cout << "====== Destructors will be called now ======" << std::endl;
	return 0;
}
