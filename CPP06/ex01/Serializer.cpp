/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:14:20 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/11/10 19:39:17 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer& obj)
{
	(void)(obj);
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	(void)obj;
	return *this;
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t i = reinterpret_cast<uintptr_t>(ptr);
	return i;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* d = reinterpret_cast<Data*>(raw);
	return d;
}
