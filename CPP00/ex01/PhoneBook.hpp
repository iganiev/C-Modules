/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:31 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/24 13:39:31 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


const int MAX_CONTACTS = 8;

class PhoneBook
{
    public:
        PhoneBook();

        void addContact();
        void searchContact() const;

    private:
        Contact contacts[MAX_CONTACTS];
        int currentIndex;

        int getValidIndex() const;
};