/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:06:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/08 17:09:15 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &obj);
		Dog& operator=(const Dog &obj);
		void makeSound() const;
		virtual ~Dog();
};

#endif
