/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:54:29 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 23:54:29 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) :_type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal &copy)
{
    *this = copy;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->_type = copy._type;

    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}


std::string		Animal::getType() const 
{
    return(this->_type);
}

void	Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}