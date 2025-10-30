/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:19:47 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/21 14:03:41 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

Harl::Harl()
{
	Complains[0] = &Harl::debug;
	Complains[1] = &Harl::info;
	Complains[2] = &Harl::warning;
	Complains[3] = &Harl::error;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning()
{
	std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARINIG", "ERROR"};
	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*Complains[0])();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*Complains[1])();
		case 2:
			std::cout << "[ WARINIG ]" << std::endl;
			(this->*Complains[2])();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*Complains[3])();
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
