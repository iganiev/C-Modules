/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:54:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 23:54:48 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    Animal(std::string type);
    Animal(Animal &copy);
    Animal &operator=(const Animal &copy);
    virtual ~Animal();

    std::string		getType() const;
	virtual void	makeSound() const = 0;

};

#endif