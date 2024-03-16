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

Cat::Cat() : Animal ("Cat"), _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat &copy) : Animal (copy), _brain(new Brain(*copy._brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    this->_type = copy._type;
    delete _brain;       // Delete existing brain
    _brain = new Brain(*copy._brain);  // Deep copy brain
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Brain	*Cat::getBrain() const
{
	return (this->_brain);
}

void	Cat::makeSound() const
{
	std::cout << _type << " Meeooowwww" << std::endl;
}