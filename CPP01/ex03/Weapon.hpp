/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:02:22 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/23 18:23:09 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include <new>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		void setType(std::string type);
		const std::string &getType() const;
		~Weapon();
};

#endif
