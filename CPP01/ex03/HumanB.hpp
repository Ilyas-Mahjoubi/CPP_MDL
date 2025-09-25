/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:01:02 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/25 17:37:08 by ilmahjou         ###   ########.fr       */
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
		Weapon *weapon;  // Pointer, not reference!
	public:
		HumanB(std::string name);  // No weapon parameter!
		void setWeapon(Weapon &weaponType);  // Add this method
		void attack();
		~HumanB();
};


#endif
