/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:58:15 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/06 00:58:15 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal ("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat &copy) : Animal (copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    this->_type = copy._type;

    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << _type << " Meeooowwww" << std::endl;
}