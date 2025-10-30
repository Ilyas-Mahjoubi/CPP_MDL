/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:22:48 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:48:45 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "--- Array Test ---" << std::endl;
	AAnimal* animals[6];
	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();

	std::cout << "\n--- Deep Copy Test ---" << std::endl;
	Dog basic;
	basic.setIdea(0, "Chase the cat!");
	basic.setIdea(1, "Eat bones!");

	Dog tmp = basic;
	std::cout << "Original: " << basic.getIdea(0) << std::endl;
	std::cout << "Copy: " << tmp.getIdea(0) << std::endl;

	tmp.setIdea(0, "Sleep all day!");
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original: " << basic.getIdea(0) << " (unchanged!)" << std::endl;
	std::cout << "Copy: " << tmp.getIdea(1) << " (changed!)" << std::endl;

	std::cout << "\n--- Cleanup ---" << std::endl;
	for (int i = 0; i < 6; i++)
		delete animals[i];
	return 0;
}
