/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:33:37 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/06 00:33:37 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
public:
    Dog();
    Dog(Dog &copy);
    Dog &operator=(const Dog &copy);
    ~Dog();

    void	makeSound() const;
};

#endif