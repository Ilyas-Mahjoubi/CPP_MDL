/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:01:59 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/21 12:36:58 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>
#include <new>

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weaponType);
		void attack();
		~HumanA();
};


#endif
