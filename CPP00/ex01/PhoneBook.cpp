/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:01:40 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/28 19:01:40 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts(), currentIndex(0) {}

void PhoneBook::addContact()
{
    if (currentIndex == MAX_CONTACTS)
    {
        std::cout << "❕Phonebook is full. Replacing the oldest contact." << std::endl;
        // Shift contacts to replace the oldest contact
        for (int i = 1; i < MAX_CONTACTS; ++i)
            contacts[i - 1] = contacts[i];
        currentIndex = MAX_CONTACTS - 1; // Reset currentIndex to point to the last contact
        contacts[currentIndex++].setContactInfo();
        std::cout << "✔ Contact added successfully." << std::endl;
    }
    else
    {
        contacts[currentIndex++].setContactInfo();
        std::cout << "✔ Contact added successfully." << std::endl;
    }
}

void PhoneBook::searchContact() const
{
    if (currentIndex == 0)
    {
        std::cout << "Phonebook is empty. No contacts to display." << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::right << "Index" << " | "
              << std::setw(10) << std::right << "First Name" << " | "
              << std::setw(10) << std::right << "Last Name" << " | "
              << std::setw(10) << std::right << "Nickname" << std::endl;

    for (int i = 0; i < currentIndex; ++i)
        contacts[i].displayContact(i);

    int index = getValidIndex();
    if (index >= 0 && index < currentIndex)
        contacts[index].displayContactDetails();
    else
        std::cout << "Invalid index. No contact to display." << std::endl;
}

int PhoneBook::getValidIndex() const
{
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return index - 1;
}
