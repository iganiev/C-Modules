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

#include "ScavTrap.hpp"

int main()
{
	ClapTrap test1("Scat");
	ScavTrap test("Shark");
	ScavTrap test2("Octopus");

	ClapTrap *a = &test1;
	ClapTrap *b = &test;


	a->attack("Fish");
	std::cout << std::endl;
	a->takeDamage(10);
	std::cout << std::endl;
	a->beRepaired(10);
	std::cout << std::endl;


	b->attack("Fish");
	std::cout << std::endl;
	b->takeDamage(15);
	std::cout << std::endl;
	b->beRepaired(15);
	std::cout << std::endl;


	test2.attack("Fish");
	std::cout << std::endl;
	test2.takeDamage(5);
	std::cout << std::endl;
	test2.beRepaired(5);
	std::cout << std::endl;
	test2.guardGate();
	std::cout << std::endl;


	return 0;
}	