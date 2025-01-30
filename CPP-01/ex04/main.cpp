/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:56:37 by nde-chab          #+#    #+#             */
/*   Updated: 2024/11/07 14:54:42 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void replaceString(std::string &line, const std::string &s1, const std::string &s2)
{
	if (s1.empty() || s1 == s2)
		return;
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
}


int main(int ac, char **av)
{
	std::string filename, s1, s2, line;

	if (ac != 4)
	{
		std::cout << "wrong nb args" << std::endl;
		return (0);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "can't be empty" << std::endl;
		return (0);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "error open infile" << std::endl;
		return (1);
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "error outfile" << std::endl;
		return (1);
	}
	while (std::getline(inputFile, line))
	{
		replaceString(line, s1, s2);
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
