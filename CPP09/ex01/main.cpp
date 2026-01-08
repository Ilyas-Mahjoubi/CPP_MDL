/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:52:21 by ilmahjou          #+#    #+#             */
/*   Updated: 2026/01/08 13:57:51 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}
	try
	{
		RPN rnp;
		rnp.calculate(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
