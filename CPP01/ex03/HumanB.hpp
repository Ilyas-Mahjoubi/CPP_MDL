/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:01:02 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/21 12:37:16 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>
#include <new>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weaponType);
		void attack();
		~HumanB();
};


#endif
