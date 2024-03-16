/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:18:27 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/06 01:18:27 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
public:
    WrongCat();
    WrongCat(WrongCat &copy);
    WrongCat &operator=(const WrongCat &copy);
    ~WrongCat();

    void	makeSound() const;
};


#endif