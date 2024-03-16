/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:44:22 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/30 15:44:22 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
    	Weapon club = Weapon("crude spiked club");
    	HumanA bob("Bob", club);
    	bob.attack();
    	club.setType("some other type of club");
    	bob.attack();
    }
    {
    	Weapon club = Weapon("");
    	HumanB jim("Jim");
    	jim.setWeapon(club);
    	jim.attack();
    	club.setType("some other type of club");
    	jim.attack();
    }
    return 0;
}