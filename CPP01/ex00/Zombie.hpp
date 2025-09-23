/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:06:18 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 16:41:27 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		void zombieSetter(std::string name);
		std::string ZombieGetter(void);
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
