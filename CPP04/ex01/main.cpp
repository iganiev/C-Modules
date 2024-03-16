/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:40:44 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 23:40:44 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;


	std::cout << std::endl;
	std::cout << std::endl;

	Animal* animal[6];

	for (int i = 0; i < 6; i++)
	{
		if (i >= 3)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		animal[i]->getType();
		animal[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		delete animal[i];
	}
	std::cout << std::endl;

	return 0;
}
