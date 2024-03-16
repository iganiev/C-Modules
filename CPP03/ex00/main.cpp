/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:27:37 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 10:27:37 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap	a("TrapClap");
	ClapTrap	b(a);
	ClapTrap	c;

	c = b;
	a.attack("b");
	b.takeDamage(9);
	b.beRepaired(100);
	c.attack("a");
	a.takeDamage(10);
	a.beRepaired(5);
	return (0);

}