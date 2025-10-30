/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:31:58 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:20:19 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		void makeSound() const;
		~Cat();
};

#endif
