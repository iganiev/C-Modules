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
#include "FragTrap.hpp"

int main()
{
	ClapTrap test("Scat");
	ScavTrap test1("Shark");
	ScavTrap test2("Octopus");
	FragTrap test3("Sea Lion");
	

	ClapTrap *a = &test;
	ClapTrap *b = &test1;
	ClapTrap *c = &test3;


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

	c->attack("Fish");
	std::cout << std::endl;
	c->takeDamage(2);
	std::cout << std::endl;
	c->beRepaired(2);
	std::cout << std::endl;


	test2.attack("Fish");
	std::cout << std::endl;
	test2.takeDamage(5);
	std::cout << std::endl;
	test2.beRepaired(5);
	std::cout << std::endl;
	test2.guardGate();
	std::cout << std::endl;

	test3.attack("Fish");
	std::cout << std::endl;
	test3.takeDamage(2);
	std::cout << std::endl;
	test3.beRepaired(2);
	std::cout << std::endl;
	test3.highFivesGuys();
	std::cout << std::endl;


	return 0;
}	