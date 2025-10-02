/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:35:49 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/02 20:50:02 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "======================================" << std::endl;
	std::cout << "========= CREATING ScavTrap ==========" << std::endl;
	std::cout << "======================================" << std::endl;

	ScavTrap name1("OMEN");
	ScavTrap name2("ISO");
	//name2 = name1;

	std::cout << "======================================" << std::endl;
	std::cout << "========= TESTING ATTACKS ============" << std::endl;
	std::cout << "======================================" << std::endl;

	name1.attack("ISO");
	name1.attack("ENEMY");
	name1.attack("BOSS");

	std::cout << "======================================" << std::endl;
	std::cout << "========= TESTING DAMAGE =============" << std::endl;
	std::cout << "======================================" << std::endl;

	name1.takeDamage(3);
	name2.takeDamage(7);

	name1.attack("1");
	name1.attack("2");
	name1.attack("3");
	name1.attack("4");
	name1.attack("5");
	name1.attack("6");
	name1.attack("7");
	//clap1.attack("3"); ==> this just to test bc he cant make an attack;

	name2.beRepaired(3);
	name2.attack("OMEN");
}
