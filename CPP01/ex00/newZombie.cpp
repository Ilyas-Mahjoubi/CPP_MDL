/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:02:54 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 16:29:50 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*nZombie;

	nZombie = new Zombie;
	nZombie->zombieSetter(name);
	std::cout << nZombie->ZombieGetter() << ":  BraiiiiiiinnnzzzZ...\n";
	return (nZombie);
}
