/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:04:28 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/08 18:59:39 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &obj);
		AAnimal& operator=(const AAnimal& obj);
		virtual void makeSound() const = 0;
		std::string getType() const;
		virtual ~AAnimal();
};

#endif
