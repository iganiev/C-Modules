/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:06:13 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/31 12:06:13 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{


    std::ifstream inputFile(filename.c_str(), std::ios::in | std::ios::out);
    if (!inputFile.is_open())
	{
        std::cerr << "Error: Unable to open input file " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Unable to open output file " << filename << ".replace" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
	{
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
		{
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }

        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Replacement completed. Output written to " << filename << ".replace" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: No strings to replace " << std::endl;
        return (1);
	}

    replaceInFile(filename, s1, s2);

    return 0;
}
