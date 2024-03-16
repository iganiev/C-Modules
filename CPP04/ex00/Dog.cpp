/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:33:02 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/06 00:33:02 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal ("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog &copy) : Animal (copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    this->_type = copy._type;

    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << _type << " Woof Woof" << std::endl;
}
