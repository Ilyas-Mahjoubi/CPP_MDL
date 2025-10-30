/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:35:49 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/23 14:06:52 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "======================================" << std::endl;
	std::cout << "========= CREATING ClapTraps =========" << std::endl;
	std::cout << "======================================" << std::endl;

	ClapTrap clap1("OMEN");
	ClapTrap clap2("ISO");

	std::cout << "======================================" << std::endl;
	std::cout << "========= TESTING ATTACKS ============" << std::endl;
	std::cout << "======================================" << std::endl;

	clap1.attack("ISO");
	clap1.attack("ENEMY");
	clap1.attack("BOSS");

	std::cout << "======================================" << std::endl;
	std::cout << "========= TESTING DAMAGE =============" << std::endl;
	std::cout << "======================================" << std::endl;

	clap2.takeDamage(3);
	clap2.takeDamage(7);
	clap1.takeDamage(3);

	clap1.attack("1");
	clap1.attack("2");
	clap1.attack("3");
	clap1.attack("4");
	clap1.attack("5");
	clap1.takeDamage(3);
	clap1.attack("6");
	clap1.attack("7");
	//clap1.attack("3"); ==> this just to test bc he cant make an attack;

	clap2.beRepaired(3);
	clap2.attack("OMEN");
}
