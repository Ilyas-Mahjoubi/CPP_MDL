/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:22:48 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 17:56:48 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing correct polymorphism ===" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	Animal adas;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;

	std::cout << "\n=== Testing WRONG polymorphism ===" << std::endl;
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;
	return 0;
}
