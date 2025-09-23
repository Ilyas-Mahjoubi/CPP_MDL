/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:56:22 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 17:09:29 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *newzombie;
	if (N <= 0)
		return (NULL);
	newzombie = new Zombie[N];
	while (i < N)
	{
		newzombie[i].zombieSetter(name);
		i++;
	}
	return (newzombie);
}
