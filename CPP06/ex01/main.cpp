/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:13:30 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/10 19:59:36 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data myData;
	myData.id = 42;
	myData.name = "ilyas";
	myData.score = 11.14;

	Data* original = &myData;
	uintptr_t serialized = Serializer::serialize(original);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Original: " << original << std::endl;
	std::cout << "Deserialized: " << deserialized << std::endl;

	if (original == deserialized)
		std::cout << "Success!" << std::endl;

	return 0;
}
