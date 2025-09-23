/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:54:31 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 17:09:57 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	int N = 5;
	Zombie *zombiehorde;
	zombiehorde = zombieHorde(N, "Horde");
	while (i < N)
	{
		std::cout << "Index " << i << ": ";
		zombiehorde[i].announce();
		i++;
	}
	delete[] zombiehorde;
	return 0;
}
