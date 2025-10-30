/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:06:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:19:35 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &obj);
		Dog& operator=(const Dog &obj);
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		void makeSound() const;
		~Dog();
};

#endif
