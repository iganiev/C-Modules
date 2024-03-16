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

Dog::Dog() : Animal ("Dog"), _brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog &copy) : Animal (copy), _brain(new Brain(*copy._brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    this->_type = copy._type;
    delete _brain;       // Delete existing brain
    _brain = new Brain(*copy._brain);  // Deep copy brain
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}

void	Dog::makeSound() const
{
	std::cout << _type << " Woof Woof" << std::endl;
}
