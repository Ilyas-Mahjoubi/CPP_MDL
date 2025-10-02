/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:35:49 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/02 21:10:04 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << std::endl;

	std::cout << "=== Testing ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("target2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Testing FragTrap ===" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("target3");
	frag.takeDamage(30);
	frag.beRepaired(15);
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Testing Construction Chain ===" << std::endl;
	ScavTrap scav2("ChainTest");
	std::cout << std::endl;

	std::cout << "=== Testing Copy Constructor ===" << std::endl;
	FragTrap frag2(frag);
	std::cout << std::endl;

	std::cout << "=== Destructors will be called now ===" << std::endl;
	return 0;
}
