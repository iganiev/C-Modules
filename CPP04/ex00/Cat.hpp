/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:56:52 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/06 00:56:52 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal 
{
public:
    Cat();
    Cat(Cat &copy);
    Cat &operator=(const Cat &copy);
    ~Cat();

    void	makeSound() const;
};

#endif