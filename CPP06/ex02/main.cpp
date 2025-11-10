/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:10:33 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/10 20:49:48 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
	int random = rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}
	std::cerr << "std::bad_cast" << std::endl;
}

int main()
{
	srand(time(NULL));

	std::cout << "================ test with the generator ===============" << std::endl;
	Base* obj1;
	obj1 = generate();
	std::cout << "Pointer version: ";
	identify(obj1);
	std::cout << "Reference version: ";
	identify(*obj1);
	delete obj1;
	std::cout << "\n=== Test with specific types ===" << std::endl;
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();
	
	Base test;
	std::cout << "A -> Pointer version: ";
	identify(a);
	std::cout << "A -> Reference version: ";
	identify(*a);
	std::cout << "B -> Pointer version: ";
	identify(b);
	std::cout << "B -> Pointer version: ";
	identify(*b);
	std::cout << "C -> Pointer version: ";
	identify(c);
	std::cout << "C -> Pointer version: ";
	identify(*c);
	std::cout << "Error: ";
	identify(test);

	delete a;
	delete b;
	delete c;
	return 0;
}
