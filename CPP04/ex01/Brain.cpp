/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:39:26 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:12:51 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor Brain called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "";
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
