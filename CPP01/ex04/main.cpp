/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:56:02 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/09/29 15:30:44 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Wrong number of arguments" << std::endl, 0);
	std::string res;
	size_t	pos = 0;
	size_t	found = 0;
	std::fstream infile(av[1]);
	std::string filename = av[1];
	std::string outname = filename + ".replace";
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string infile_contents;
	std::string str;

	if (s1.empty())
	{
		std::cout << "the string is empty." << std::endl;
		return 1;
	}
	if (filename.empty())
	{
		std::cout << "the file is empty :(" << std::endl;
		return 1;
	}
	if (!(infile.is_open()))
	{
		std::cout << "you cant open this file" << std::endl;
		return 1;
	}

	std::ofstream outfile(outname.c_str());
	while (std::getline(infile, str))
		infile_contents += str + "\n";
	while ((found = infile_contents.find(s1, pos)) != std::string::npos)
	{
		res += infile_contents.substr(pos, found - pos);
		res += s2;
		pos = found + s1.length();
	}
	res += infile_contents.substr(pos);
	outfile << res;
	infile.close();
	outfile.close();
	return 0;
}
