/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:02:30 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/28 19:02:30 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the Awesome 80s Phonebook!" << std::endl;

    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT" || std::cin.eof())
        {
            std::cout << "Goodbye! Exiting the Awesome 80s Phonebook." << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        std::cin.clear();
    }
    return 0;
}
