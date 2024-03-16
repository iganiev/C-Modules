/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:03:08 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/28 19:03:08 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include <cctype> 

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

void Contact::setContactInfo()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, _firstName);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, _lastName);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, _nickname);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, _phoneNumber);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, _darkestSecret);
}


void Contact::displayContact(int index) const
{
    std::cout << std::setw(10) << std::right << index + 1 << " | "
              << std::setw(10) << std::right << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << " | "
              << std::setw(10) << std::right << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << " | "
              << std::setw(10) << std::right << (_nickname.length() > 10 ? _nickname.substr(0, 9) + "." : _nickname) << std::endl;
}

void Contact::displayContactDetails() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nick Name: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}