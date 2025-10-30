/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:22:48 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:09:48 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

// int main()
// {
// 	std::cout << "--- Basic Test ---" << std::endl;
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;
// 	delete i;

// 	std::cout << "\n--- Array Test (Half Dogs, Half Cats) ---" << std::endl;
// 	Animal* animals[6];
// 	for (int idx = 0; idx < 3; idx++)
// 		animals[idx] = new Dog();
// 	for (int idx = 3; idx < 6; idx++)
// 		animals[idx] = new Cat();

// 	std::cout << "\n--- Deep Copy Test ---" << std::endl;
// 	Dog original;
// 	Dog copy = original;

// 	std::cout << "\n--- Cleanup Array ---" << std::endl;
// 	for (int idx = 0; idx < 6; idx++)
// 		delete animals[idx];
// 	return 0;
// }

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "--- Deep Copy Test ---" << std::endl;
	Dog original;
	original.setIdea(0, "I want to chase cats!");
	original.setIdea(1, "I love bones!");

	Dog copy = original;
	std::cout << "\nOriginal ideas: " << original.getIdea(0) << ", " << original.getIdea(1) << std::endl;
	std::cout << "Copy ideas: " << copy.getIdea(0) << ", " << copy.getIdea(1) << std::endl;

	copy.setIdea(0, "I want to sleep!");
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea[0]: " << copy.getIdea(0) << std::endl;

	std::cout << "\n--- Array Test ---" << std::endl;
	Animal* animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
