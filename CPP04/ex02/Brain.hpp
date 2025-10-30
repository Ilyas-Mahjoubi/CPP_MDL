/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:39:29 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/10/27 15:19:14 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &obj);
		Brain& operator=(const Brain &obj);
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
		~Brain();
};

#endif
